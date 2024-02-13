![Open in Codespaces](https://classroom.github.com/assets/open-in-codespaces-abfff4d4e15f9e1bd8274d9a39a0befe03a0632bb0f153d0ec72ff541cedbe34.svg)
# Gradebook
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

You will be creating a program to help a teacher calculate final grades for a class.  The program will calculate a final letter grade base on a standard 90/80/70/60 scale.

You will be taking input from a file that contains all of the names and grades of each student. You will find the average for each student and output each student's final letter grade.

1. Your program should accept the filename from the command-line as shown in the example below
	* Add error checking to make sure the appropriate number of command line arguments were passed
2. Read in the input file correctly
	* Add error checking to make sure the file was opened correctly
3. Calculate the final grade for each student
4. Generate a report that matches the example below
	* Show table of grades with final letter grade
	* Print off all names with the **floating point** average 

### Input file format

The input file will have the following format:

```
First Line: Number of assignments
Second line: Number of students
Third Line: Student Names, space delimited
Fourth+ Line(s): Grades for all students for one assignment, space delimited.
```

Example of input file format:

```
8
5
Joel Bob Susan Hillary John
100 92 84 76 68
99 91 83 75 67
98 90 82 74 66
97 89 81 73 65
96 88 80 72 64
95 87 79 71 63
94 86 78 70 62
93 85 77 69 0 
```

**A sample input file is provided, please add your input to the `input.txt` file for testing**

Your program should:
* Calculate final grades
* Print the report

### Requirements

* Use the given template and **filename** for your submission.
* You must use functions in an appropriate way
* Must use dynamic multidimensional arrays
	* 2D array to hold student names
		* Student names will not be longer than 10 characters
	* 2D array to hold all grades
		* Use the values from the file as the sizes for your arrays
	* Array to hold final letter grades
		* Use the values from the file as the sizes for your arrays
* Because your arrays are dynamic your program should be able to handle a file of any reasonable size. (There may be MANY students and grades.)


#### Required Functions (You must fill in the parameters):

```c
void getGrades(...);
void printGrades(...);
void getStudents(...);
void printStudents(...);
void calcGrades(...);
void printFinalLetterGrades(...);
void printPercentageGrades(...);
```

### Example Output

```
$ ./a.out infile.txt
      Joel       Bob     Susan   Hillary      John

       100        92        84        76        68
        99        91        83        75        67
        98        90        82        74        66
        97        89        81        73        65
        96        88        80        72        64
        95        87        79        71        63
        94        86        78        70        62
        93        85        77        69         0
         A         B         B         C         F



      Joel : 96.50 %
       Bob : 88.50 %
     Susan : 80.50 %
   Hillary : 72.50 %
      John : 56.88 %
```
