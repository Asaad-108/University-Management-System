# University Management System

This project is a C++ implementation of a University Management System. It includes classes to manage various entities such as `MyString`, `Date`, `Person`, `Student`, `Teacher`, and `Info`. The system provides functionalities to read from and write to files, compare objects, and handle dynamic memory management.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Classes Overview](#classes-overview)
- [File Handling](#file-handling)
- [License](#license)

## Features

- Custom string class `MyString` with basic operations.
- Date class with age calculation functionality.
- Person class as a base class for Student and Teacher.
- Student class with specific attributes and methods.
- Teacher class with specific attributes and methods.
- File handling for reading and writing `MyString` objects.
- Comparison operators and methods for different classes.
- Dynamic memory management for arrays of objects.

## Getting Started

### Prerequisites

To compile and run this project, you need:

- A C++ compiler (e.g., `g++`)
- A terminal or command prompt

### Installation

1. Clone the repository:

    ```sh
    git clone https://github.com/yourusername/university-management-system.git
    cd university-management-system
    ```

2. Compile the project:

    ```sh
    g++ -o university_management main.cpp
    ```

    Replace `main.cpp` with the name of your main source file if different.

## Usage

Run the compiled program:

```sh
./university_management
