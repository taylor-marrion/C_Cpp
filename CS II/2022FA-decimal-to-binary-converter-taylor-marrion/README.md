[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-9f69c29eadd1a2efcce9672406de9a39573de1bdf5953fef360cfc2c3f7d7205.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=9360839)
# Decimal to Binary Converter
## Points: 10

## Submission

`commit` and `push` your code to the `master` branch on the remote GitHub repository **before** the deadline.

You may perform these action within the Terminal in VSCode or you can use the GUI within VSCode to perform these actions. **Always verify your content has been pushed by navigating to GitHub and viewing your assignment.**

## Clone

See [Prerequisites](#prerequisites) below before performing this step.

`clone` this repo to your local machine using the link provided on the GitHub repo page or clicking the "Open in Visual Studio Code" button above.

Use the included files as your template to start the program maintaining the filenames given. **Do not modify the filename of the C file provided.**

## Running your program
### Prerequisites

* Ensure [Docker Desktop](https://www.docker.com/products/docker-desktop) is installed
* Ensure [Visual Studio Code](https://code.visualstudio.com/download) is installed
* Ensure the [Remote - Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) extension is installed in VSCode
* Ensure the [GitHub Classroom](https://marketplace.visualstudio.com/items?itemName=GitHub.classroom) extension is installed in VSCode

### Running

* Open this repo in VSCode
    * The docker container configuration is included in this repo
    * If all prerequisites are installed, you will be prompted to open inside the container
    * If the container fails to load, use the following steps
        * Press F1, and select `Add Development Container Configuration Files`... command for Remote-Containers
        * Select `Show All Definitions...`
        * Select `C++`
        * Select `debian-11`
            * You may be prompted to re-open VSCode
* Make your edits to the provided files
* Open the terminal built into VSCode (at the bottom of the screen by default)
    * This terminal will be configured to use the Docker container
* Each assignment is configured with a Makefile so you can run `make run` and it will build your C program and run the executable
    * Alternatively, you can run the `gcc` command yourself and use `./` to execute your file

## Description

In this assignment you will convert a positive integer into a binary value by using a stack implemented with a singly linked list.

- [ ] 1. Ask the user to enter in the integer to be converted to binary.
    - **Assume all entered values are positive (greater than 0)**
- [ ] 2. Convert decimal to binary using a stack with a singly linked list.

**HINT: Use modulus, remember binary is base 2**

### Example Math

Example showing how to find the binary values and reducing. The result of this conversion is shown in the example output section.

```
93 % 2 = 1
93 / 2 = 46

46 % 2 = 0
46 / 2 = 23

23 % 2 = 1
23 / 2 = 11

11 % 2 = 1
11 / 2 = 5

5 % 2 = 1
5 / 2 = 2

2 % 2 = 0
2 / 1 = 1

1 % 2 = 1
1 / 2 = 0
```

## Requirements

* You must use a linked list stack
* Do not use recursion
* Formatting should match **exactly** as the example below (note the spacing)

Required Functions (You must fill in the parameters):
```c
// puts a number on the stack
void push(...)

// takes a number off the stack
void pop(...)

// returns the value of the number on the top of the stack
int top(...)

// prints the contents of the stack (top to bottom)
void printStack(...)

// prints off the binary version of a decimal number
void toBin(...)
```


## Example Output

```
$ ./a.out
Enter an integer: 93
 1  0  1  1  1  0  1 
```
