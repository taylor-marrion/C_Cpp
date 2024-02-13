![Open in Codespaces](https://classroom.github.com/assets/open-in-codespaces-abfff4d4e15f9e1bd8274d9a39a0befe03a0632bb0f153d0ec72ff541cedbe34.svg)
# CSC-150 Review: Arrays & Random Numbers
## Points: 10

## Submission

`commit` and `push` your code to the `main` branch on the remote GitHub repository **before** the deadline.

You may perform these action within the Terminal in Codespaces/VSCode or you can use the GUI within Codespaces/VSCode to perform these actions. **Always verify your content has been pushed by navigating to GitHub and viewing your assignment.**

## Opening and Editing

Open your assignment in GitHub Codespaces by clicking the green "Code" button in the top right corner of the webpage for your repo on GitHub. Select the "Codespaces" tab and click "Create codespace on main" to open a new codespace.

This will open a web interface that is very similar to VS Code. You can use this interface to open and edit your assignment. Additionally, if you prefer, you may use VS Code to open your code locally. There is an extension called GitHub Codespaces to link your remote codespace to your local VS Code located here: <https://marketplace.visualstudio.com/items?itemName=GitHub.codespaces>

Use the included files as your template to start the program maintaining the filenames given. **Do not modify the filename of the C file provided.**

## Running your program

### Running

* Open this repo in GitHub Codespaces
* Make your edits to the provided files
* Open the terminal built into Codespaces (at the bottom of the screen by default)
* Each assignment is configured with a Makefile so you can run `make run` and it will build your C program and run the executable
    * Alternatively, you can run the `gcc` command yourself and use `./` to execute your file

## Description

For this assignment, you will be reviewing some major topics from CSC-150 that you must understand for this course. You will be creating a program that uses arrays, random numbers, searching, and simple math operations.

1. Ask the user how many numbers they would like generated. Your program will then generate that many numbers with a range of 0-1000 into an array of the same size. This means the array should be dynamically allocated, using the number the user entered.
2. Find the smallest and largest numbers in the array.
    * Print out these values and indices of those values in the array.
3. Then, find the sum and average (integer average) of the numbers in the array.
4. Finally, print out the entire array to verify.

### Requirements

* Use the given template and **filename** for your submission.
* You MUST use functions where appropriate! Some are provided, but you can add more.
    * Examples may be:
        * `findSum()`
        * `findMin()`
        * `findMax()`
        * `findVal()`
* Output **MUST** be formatted **EXACTLY** as below (number alignment, spacing, etc.)
    * Count the spaces, make sure it's correct.
* Make sure you include both 0 **and** 1000 in your random generation
* Use `rand()` for number generation and `srand()` to set the random generator time as a seed value

### Required Functions

```c
int findMin(int arr[], int size);
int findMax(int arr[], int size);
int findSum(int arr[], int size);
```

### Example Output

```
$ ./a.out
Enter an integer: 30
max:    992 pos:      3
min:      2 pos:     24
avg:    445
sum:  13371

 Pos  :   Val
-------------
   0  :   309
   1  :   607
   2  :   387
   3  :   992
   4  :   835
   5  :   376
   6  :    68
   7  :   490
   8  :   179
   9  :   571
  10  :   889
  11  :   888
  12  :   243
  13  :   272
  14  :   749
  15  :   381
  16  :   864
  17  :    99
  18  :   438
  19  :    32
  20  :   628
  21  :   203
  22  :   460
  23  :    92
  24  :     2
  25  :   987
  26  :    79
  27  :   490
  28  :   680
  29  :    81
```
