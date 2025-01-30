# TheoVision

## Description
Interactive 3D environment. Move, rotate, scale 3D objects. manipulate geometry and adjust materials and rendering settings.

<img width="798" alt="theovision" src="https://github.com/user-attachments/assets/1cc87d94-08b6-40ef-84f7-93a1f44b9c30" />



## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Dependencies](#dependencies)
- [References](#references)

## Usage
- Click on an object to select it.
- Tapping "a" allows you to select/deselect all objects.
- Tapping "r" allows you to rotate the selected object by moving the cursor around the screen. Clicking will apply the rotation.
- Tapping "g" allows you to move the selected object by moving the cursor around the screen. Clicking will apply the translation.
- Tapping "s" allows you to move the selected object by moving the cursor around the screen. Clicking will apply the scale.
- Different shaders can be applied by replacing the shader object in the Viewport class.

## Prerequisites

Before you begin, ensure you have met the following requirements:

- A C++ compiler such as GCC, Clang, or MSVC
- CMake (for build configuration)

## Dependencies

This project requires the following dependencies:

- wxWidgets 3.0 or higher
- pkg-config
- glfw

### Installing Homebrew
paste into the terminal and follow the instructions:
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
 ```
Verify Homebrew has successfully been installed by running "brew doctor"

### Installing wxWidgets
Download the latest macos source from the [wxwidgets website](https://www.wxwidgets.org/downloads/).\
Unpack and cd into the directory\
Run the following in the terminal:
```bash
./configure
make
sudo make install
```
test wx-config is in path by running 
```
wx-config --version
```

### Installing pkg-config
Make sure you have Homebrew installed if you are on mac
run in the terminal:
```bash
brew install pkg-config
```
Test it was correctly installed by running "pkg-config --version"

### Installing glfw
Run in the terminal:
```bash
brew install glfw
```

## References
- [BVH Algorithm](https://www.researchgate.net/publication/226039567_Grid-based_SAH_BVH_construction_on_a_GPU)
- [Ray Triangle Intersection](https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm)
