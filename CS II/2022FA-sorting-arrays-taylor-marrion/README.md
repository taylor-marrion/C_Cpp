[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-9f69c29eadd1a2efcce9672406de9a39573de1bdf5953fef360cfc2c3f7d7205.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=9354502)
# Sorting Arrays
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

For this assignment you need to make bubble sort algorithm that will sort an array. Do not copy an online program.

Please print your array before and after the sorting.

Perform the following tasks:
1. Print the **unsorted** array **before** you run the bubble sort algorithm
2. During the bubble sort, you must print out the entire **unsorted portion** of the array after each comparison (even if a swap was not encountered)
3. Print out the final **sorted** array **after** the bubble sort has completed

**HINT:** You will need to use nested loops to complete this algorithm, but I suggest starting with a single loop that goes through the list one time and does the comparisons and swaps for one pass through the data.

### Input file format

The input file will have the following format:
```
First line: Number of values in the input file for you to sort
Second+ Line(s): Values to add to your array
```

Example of an input files format:
```
10
50
78
83
92
100
0
4
72
3
19
```

**Sample input files are provided, please add your input to the `input.txt` file for testing**

### Requirements

* Use the given template and **filename** for your submission.
* You must use functions in an appropriate way
* Your program must read input from a file in the proper format, NOT stdin
* Your program should accept the filename from the command-line as shown in the example below
* Your format must match mine **exactly** (width of 3 with space for numbers)
* Your array should be sized dynamically using the size from the input file

#### Required Functions

```c
void bubbleSort(int arr[], int size);
void printArr(int arr[], int size);
```


### Example Output

```
$ ./a.out input.txt

** Before Sorting**
  50  78  83  92 100   0   4  72   3  19

== Bubble Sort ==
  50  78  83  92 100   0   4  72   3  19
  50  78  83  92 100   0   4  72   3  19
  50  78  83  92 100   0   4  72   3  19
  50  78  83  92 100   0   4  72   3  19
  50  78  83  92   0 100   4  72   3  19
  50  78  83  92   0   4 100  72   3  19
  50  78  83  92   0   4  72 100   3  19
  50  78  83  92   0   4  72   3 100  19
  50  78  83  92   0   4  72   3  19 100
  50  78  83  92   0   4  72   3  19
  50  78  83  92   0   4  72   3  19
  50  78  83  92   0   4  72   3  19
  50  78  83   0  92   4  72   3  19
  50  78  83   0   4  92  72   3  19
  50  78  83   0   4  72  92   3  19
  50  78  83   0   4  72   3  92  19
  50  78  83   0   4  72   3  19  92
  50  78  83   0   4  72   3  19
  50  78  83   0   4  72   3  19
  50  78   0  83   4  72   3  19
  50  78   0   4  83  72   3  19
  50  78   0   4  72  83   3  19
  50  78   0   4  72   3  83  19
  50  78   0   4  72   3  19  83
  50  78   0   4  72   3  19
  50   0  78   4  72   3  19
  50   0   4  78  72   3  19
  50   0   4  72  78   3  19
  50   0   4  72   3  78  19
  50   0   4  72   3  19  78
   0  50   4  72   3  19
   0   4  50  72   3  19
   0   4  50  72   3  19
   0   4  50   3  72  19
   0   4  50   3  19  72
   0   4  50   3  19
   0   4  50   3  19
   0   4   3  50  19
   0   4   3  19  50
   0   4   3  19
   0   3   4  19
   0   3   4  19
   0   3   4
   0   3   4
== Sorting Completed ==

** After Sorting**
   0   3   4  19  50  72  78  83  92 100
```
