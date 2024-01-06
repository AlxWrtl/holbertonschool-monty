# Monty Bytecodes Interpreter

## Description

This project is a Monty Bytecodes interpreter written in C. Monty 0.98 is a scripting language that is first compiled into Monty bytecodes. It relies on a unique stack with specific instructions to manipulate it. This interpreter reads Monty bytecodes files and executes them.

### Motivation

The main motivation behind this project is to learn more about stack data structures, memory management, and the intricacies of interpreting a higher-level language.

### Problem Solved

The interpreter can execute a variety of commands on a stack, such as adding, swapping, and removing elements. This provides a basic, but powerful toolset for manipulating data in a LIFO (Last In, First Out) manner.

### Learnings

Key learnings from this project include dynamic memory allocation, file operations in C, string manipulations, and the implementation of stack operations.

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Supported Operations](#supported-operations)

## 🗂️ Files
- `monty.h`: Header file with all function prototypes and data structures.
- `main.c`: Main entry point for the interpreter.
- `opcode_functions.c`: Contains functions for each opcode.
- `handle_opcode.c`: Functions related to stack operations.
- `safety.c`: Helper functions used across the program.

## Installation

To install the Monty Bytecodes Interpreter:
1. Clone the repository: `git clone [repository-link]`
2. Compile the code: `gcc *.c -o monty`

## Usage

To use the interpreter:
1. Write your Monty bytecodes in a file.
2. Run the interpreter with the file as an argument: `./monty file.m`

### Supported Operations

| Opcode  | Description                                      |
|---------|--------------------------------------------------|
| push    | Pushes an element to the stack.                   |
| pall    | Prints all the values on the stack.              |
| pint    | Prints the value at the top of the stack.        |
| pop     | Removes the top element of the stack.            |
| swap    | Swaps the top two elements of the stack.         |
| add     | Adds the top two elements of the stack.          |
| nop     | Does nothing.                                    |

## Contributing

Contributions to enhance the Monty Bytecodes Interpreter are welcome! Please open an issue or create a pull request with your suggestions.

## Acknowledgments

This project is inspired by the Monty language and its applications in higher-level programming.

## Contact

For any inquiries or feedback, contact the project maintainer:

- `Thomas Viard` || `Alexandre Wertel`

## 🔗 Authors Links

[![github](https://img.shields.io/badge/Thomas_Github-000?style=for-the-badge&logo=ko-fi&logoColor=white)](https://github.com/ThomasVrd11)

[![github](https://img.shields.io/badge/Alexandre_Github-000?style=for-the-badge&logo=ko-fi&logoColor=white)](https://github.com/SuperPims?tab=repositories)

### Notes

- This project is a learning tool and may not cover all aspects of the Monty language.
- Future improvements could include extended error handling and support for more complex operations.
