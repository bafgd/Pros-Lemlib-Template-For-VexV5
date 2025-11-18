#include "main.h"
#include "lemlib/api.hpp"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include <sys/syslimits.h>

//declaration

//Controller
pros::Controller master(pros::E_CONTROLLER_MASTER);

//Left
pros::MotorGroup left_motors({-1, 2, -3});

//Right
pros::MotorGroup right_motors({4, -5, 6});

// Standalone intake motor (port 10)
pros::Motor intake(10);

// IMU on port 10
pros::Imu imu(10); 

// No Tracking encoders (add if you plan on using specific tracking odometry)

//piston for tonuge on port A
pros::adi::DigitalOut tongue('A');  // Pneumatic clamp on ADI port A

// Initial state of pneumatic tonuge
bool tongueValue = false;

// Initial state of lock for tonuge
bool tongueLock = false;


//Controls (L2 = intake, R2 = outtake, B = toggle tonuge)
constexpr auto intake_in = pros::E_CONTROLLER_DIGITAL_L2;
constexpr auto intake_out = pros::E_CONTROLLER_DIGITAL_R2;
constexpr auto tongue_toggle = pros::E_CONTROLLER_DIGITAL_B;



//--------Lemlib DriveTrain Start --------

//(change based on bot's drivetrain config)
lemlib::Drivetrain drivetrain(
    &left_motors,                // Left motor group
    &right_motors,               // Right motor group
    10,                          // Track width (inches)
    lemlib::Omniwheel::NEW_4,    // Wheel type (4" omni)
    360,                         // Max RPM
    2                            // Drift (measured experimentally)
);

// Odometry sensor setup (nothing but imu, change if adding tracking wheels)
lemlib::OdomSensors sensors(
    nullptr,    // Vertical tracking wheel 1
    nullptr,                     // Vertical tracking wheel 2 (none)
    nullptr,  // Horizontal tracking wheel 1
    nullptr,                     // Horizontal tracking wheel 2 (none)
    &imu                         // IMU
);

// PID Controller settings for forward/backward motion (Leave as is)
lemlib::ControllerSettings lateral_controller(
    10, 0, 3, 3,  // kP, kI, kD, anti-windup
    1, 100,        // Small error (inches), timeout (ms)
    3, 500,        // Large error (inches), timeout (ms)
    20             // Max acceleration (slew)
);

// PID Controller settings for turning (Leave as is)
lemlib::ControllerSettings angular_controller(
    2, 0, 10, 3,  // kP, kI, kD, anti-windup
    1, 100,        // Small error (degrees), timeout (ms)
    3, 500,        // Large error (degrees), timeout (ms)
    0              // Max acceleration (slew)
);

// Create LemLib chassis (Leave as is)
lemlib::Chassis chassis(
    drivetrain, 
    lateral_controller, 
    angular_controller, 
    sensors);

//--------Lemlib DriveTrain End --------


//initialize
void initialize() {
    chassis.calibrate();  // Calibrate IMU
}

//leave as is
void disabled() {}

//leave as is
void competition_initialize() {}


//Main autonomus function. Add code here to make it run autonomus
void autonomous() {
    // Example autonomous routine
    chassis.moveToPoint(24, 0, 3000);  // Move forward 24"
    chassis.turnToHeading(90, 1000);   // Turn to 90°
}


//Driver Control
void opcontrol() {
    while (true) {
        // Arcade drive (single-stick)
        chassis.arcade(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X));

        // --- Intake Motor Control ---
        // L2 = in, L1 = out (declared at the top)
        if (master.get_digital(intake_in)) {
            intake.move(127);  // Full forward
        } 
        else if (master.get_digital(intake_out)) {
            intake.move(-127); // Full reverse
        } 
        else {
            intake.brake();    // Stops motor when button released
        }


        // --- Pneumatics Toggle ---
        // A button toggles the pneumatic clamp
        if (master.get_digital(tongue_toggle)) {
            tongueValue = !tongueValue;
            tongue.set_value(tongueValue);
            tongueLock = true;
        } 
        else if(!master.get_digital(tongue_toggle) && tongueLock) {
            tongueLock = false;
        }
        

        pros::delay(20); // Delay to reduce CPU usage
    }
}