![Open in Codespaces](https://classroom.github.com/assets/open-in-codespaces-abfff4d4e15f9e1bd8274d9a39a0befe03a0632bb0f153d0ec72ff541cedbe34.svg)
# Shift Cipher
## Points: 20

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

In this assignment you will use your knowledge of strings to write a program that will encrypt/decrypt messages.

1. Create a menu that asks the user whether they want to (in this order):
	1. Change shift value
		* Make sure you set it to `3` by default
		* When testing, I don't recommend using anything higher than 10
	2. Encrypt a message
	3. Decrypt a message
	4. Quit

2. The user should then be able to type in a message up to `500` characters in length that will be encrypted/decrypted
	* You will use what is called a shift cipher to encrypt the messages
	* A shift cipher takes your input, goes through it one letter at a time, and "shifts" that value a certain amount of places to change its value
	* Your program should _encrypt_ messages by **subtracting** a value from the character, and _decrypt_ by **adding** that value.

3. Your program should continue to bring up the main menu until the user selects the option to quit.

## Requirements:

Use the following ideas:
* functions
* function returns
* function parameters
* strings
* loops
* if statements

Required Functions:

```c
int getUserChoice()
int getShift()
void getString(char buf[])
void encrypt(char buf[], int shift)
void decrypt(char buf[], int shift)
```

The parameters of these functions are given and do not need to be modified. However, the body of these functions need to be filled in as does the body of `main()`

* `getUserChoice()` will be used to print the menu and get the users choice of `1`, `2`, `3`, or `4`
	* Your program should handle invalid menu options by either quitting or asking for a new value.

* `getString()` will be used to get the string the user wants encrypted/decrypted

* Do not use any user input functions in `main()` such as `scanf()` or `fgets()`

* Your default shift value should be set to `3`

* **DO NOT** encrypt/decrypt the newline `\n` character or `NULL` terminator `\0` character in your strings
* **DO NOT** encrypt/decrypt spaces
* **DO NOT** print inside encrypt/decrypt functions, only print inside functions that are made for that purpose


## Example Output

```
$ ./a.out 
-------------------------------
| 1) Change Shift (default 3) |
| 2) Encrypt a message        |
| 3) Decrypt a message        |
| 4) Quit                     |
-------------------------------
Option: 2
 Input: Joel Wohnoutka
Output: Glbi Tleklrqh^


-------------------------------
| 1) Change Shift (default 3) |
| 2) Encrypt a message        |
| 3) Decrypt a message        |
| 4) Quit                     |
-------------------------------
Option: 3
 Input: Glbi Tleklrqh^
Output: Joel Wohnoutka


-------------------------------
| 1) Change Shift (default 3) |
| 2) Encrypt a message        |
| 3) Decrypt a message        |
| 4) Quit                     |
-------------------------------
Option: 2
 Input: See how this doesn't encrypt spaces?
Output: Pbb elt qefp albpk$q bk`ovmq pm^`bp<


-------------------------------
| 1) Change Shift (default 3) |
| 2) Encrypt a message        |
| 3) Decrypt a message        |
| 4) Quit                     |
-------------------------------
Option: 1
Enter new shift value: 2


-------------------------------
| 1) Change Shift (default 3) |
| 2) Encrypt a message        |
| 3) Decrypt a message        |
| 4) Quit                     |
-------------------------------
Option: 2
 Input: Hello
Output: Fcjjm


-------------------------------
| 1) Change Shift (default 3) |
| 2) Encrypt a message        |
| 3) Decrypt a message        |
| 4) Quit                     |
-------------------------------
Option: 1
Enter new shift value: 10


-------------------------------
| 1) Change Shift (default 3) |
| 2) Encrypt a message        |
| 3) Decrypt a message        |
| 4) Quit                     |
-------------------------------
Option: 2
 Input: Hello
Output: >[bbe


-------------------------------
| 1) Change Shift (default 3) |
| 2) Encrypt a message        |
| 3) Decrypt a message        |
| 4) Quit                     |
-------------------------------
Option: 4
```
