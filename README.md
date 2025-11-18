# VEX Robotics Coding Template

A simple, beginner-friendly codebase to help new members learn how to program VEX robots efficiently.  
This project provides a streamlined starting point using [PROS](https://pros.cs.purdue.edu/), [LemLib](https://lemlib.github.io/), and standard C++ conventions.

---

## 🧠 Overview

This template is designed to make it easier for students to:
- Learn the basics of VEX robotics programming.
- Understand project structure and organization in PROS.
- Quickly start building autonomous and driver control programs.

---

## 🗂 Where to Start

The code with comments is located here (will not compile):
[Open main.cpp](PROS-LEMLIB%20Template/src/main.cpp)

Open this file in **Visual Studio Code** to see the full code with explanation, including:
- Motor and sensor setup
- Pneumatics example
- LemLib drivetrain and controllers
- Autonomous and driver control functions

This file contains the latest version of PROS and Lemlib as of November 1st, 2025.

The main template code without detailed comments is located here (will compile):
[Open main.cpp](63310%20Main/src/main.cpp)

---

## ⚙️ Requirements

Before getting started, make sure you have the following installed:

**Software:**
- **[PROS](https://pros.cs.purdue.edu/)** (VEX V5 development environment)  
- **[Visual Studio Code](https://code.visualstudio.com/)**  
- **[LemLib](https://lemlib.readthedocs.io/en/stable/index.html)** (for motion control and odometry)  
- **C++ toolchain:**  
  - **Windows:** [MSYS2](https://www.msys2.org/)  
    - **Follow the instructions:** [YouTube-Video](https://www.youtube.com/watch?v=DMWD7wfhgNY)
    - **No need to install CodeRunner**
  - **macOS:** Xcode Command Line Tools (`xcode-select --install`)
    - **Follow the instructions:** [YouTube-Video](https://www.youtube.com/watch?v=v2_Pth8MrKA) 
    - **No need to install CodeRunner**

**Hardware:**   
- ⚠️ You must have a working personal laptop (Windows or Mac) with administrator privileges.  
- 🖥️ Desktops are allowed, but coding and uploading during competition may be more difficult.

---

## 🚀 Usage

> You can skip this step and copy the code later from the [main.cpp (no comments)](63310%20Main/src/main.cpp)

1. Open this project folder in **Visual Studio Code**.  
2. Confirm that **PROS** and **LemLib** are installed correctly.  
3. Using GitHub, pull the `main` branch
4. Edit and expand the code as needed for your robot:  
   - Update motor ports, sensors, and configurations in the setup sections.  
   - Add autonomous routines and driver controls.  
   - Test frequently and document your changes.

> ⚠️ **Note:** This is a template for educational use.  
> Customize it before using it for competition.

---

## ✅ How to install/use PROS & LemLib

1. Navagate to the extensions page on VSCode (left menu bar, looks like 4 blocks)
2. Search up PROS
3. Install PROS
4. Navagate to the PROS extension on the left menu bar
5. Open the "**Intergrated Terminal**"
    - There will be 2 lines of code you need to copy and paste into the terminal (appears at the **bottom**) (for convience, I have pasted them bellow. Run the 2 lines seperatly)
        - `pros c add-depot LemLib https://raw.githubusercontent.com/LemLib/LemLib/depot/stable.json`
        - `pros c apply LemLib`
    - After running those, paste this line to update everything
        - `pros c upgrade`
5. Restart your computer
6. Move on to **How to create a project** bellow

---

## ✅ How to create a project

1. Navagate to the PROS extension on the left menu bar
2. Find the button near the left side named "**Create Project**"
3. Name your file (at the top)
4. Choose the latest version
5. Your project has been created with the basic public template provided by PROS
    - You may copy and paste the [main.cpp (no comments)](63310%20Main/src/main.cpp) into your project's main.cpp in the `src` file

---

## ⛭ How to Upload

1. Navagate to the PROS extension on the left menu bar
2. Find the button near the left side named "**Build & Upload**"
    - Clicking it will automatically overwrite code already on SLOT 1 ofthe Vex Brain
**OPTIONAL**
3. If you want to upload code to seperate slots to test
    - Navagate to the PROS extension on the left menu bar
    - Open the "**Intergrated Terminal**"
    - Commands you can type:
        - `pros`
            - Gives all commands and what each does
        - `pros m`
            - **ONLY** builds the code
        - `pros mu`
            - Builds and uploads the code

---

## 💡 Contributing

If you make improvements or fixes:
- Feel free to edit and share your version with others.
- Document your changes clearly so others can learn from them.

This project is meant to help everyone learn — contributions and feedback are always welcome!

---

## 📚 Helpful Resources

- [PROS Documentation](https://pros.cs.purdue.edu/v5/)  
- [LemLib Docs](https://lemlib.readthedocs.io/en/stable)  
- [VEX Forum](https://www.vexforum.com/)  
- [C++ Reference](https://cplusplus.com/reference/)
- [W3Schools C++](https://www.w3schools.com/cpp/default.asp)

---

### ✅ Notes
This project is **not affiliated** with VEX Robotics or Purdue University.  
It’s a **learning resource** built to make coding VEX robots easier for students.

Created by 63310A Katy Robotics Coding Department.
