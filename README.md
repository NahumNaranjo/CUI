# Ariadne
A CMD UI engine, it's designed to provide a simple ui for command-line-based programs.

**CL Crossover**: This library is part of the CLearning ecosystem.

## Features

- **Automatic menu creation**: Create a menu and display it with a few calls.
- **Styled titles**: Customize title output using `displayTitle()`.
- **Lightweight**: Designed for small command-line tools.

## Install instructions

Install the package into your workspace using CL or download and manually put them into your project.

## File Structure

- `cui.c`: Implementation of UI helpers.
- `cui.h`: Public API declarations.

## Usage
- create a MenuOption array with the following format
```c
    MenuOption options[] = {
        "option", "o"
    };
```
- Declare an empty size_t and create a Menu pointer to the result of CreateMenu()
```c
    size_t count;
    Menu* menu = createMenu("C User Interface", options, count);
```
- Display the menu and title (if needed)
```c
    displayTitle(menu->title);
    char result = *displayMenu(menu);
```

- You're free to compare the result, it'll be a char with the second parameter of the selected option.

### Version
1.0.0 - CUI, C User Interface engine (lib)
Author: Nahum Naranjo