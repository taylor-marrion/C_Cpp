![Open in Codespaces](https://classroom.github.com/assets/open-in-codespaces-abfff4d4e15f9e1bd8274d9a39a0befe03a0632bb0f153d0ec72ff541cedbe34.svg)
# Property Tacker
## Points: 15

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

This assignment will make use of structs and reading from files.

For this assignment you must create an array of `struct`s that will record the rental properties that a person owns.

The goal of this assignment is to have you read in this information from a file and save it into an array of structures which represent the inventory items.

You need to complete the following operations on the data:
1. Calculate total rental **income** for Owner1
2. Calculate total maintenance costs for Owner2
3. Average price per bedroom for each owners
4. Count # of houses owned by each owner (search for the string `house`)
5. Average price of all properties (combining both owners)

**A max of 50 properties per owner will be read in from the file.**

### Input file format

The input file will have the following format:

```
1st line is the number of properties for the owner
2nd line is the type of property (house, apartment, condo, etc.)
3rd line is the monthly rental cost
4th line is the monthly maintenance cost
5th line is number of bedrooms
6th line is number of bathrooms

lines 2-6 will repeat for as many times specified in line 1
There will be 2 input files; each file will have one set of data.
```

**NOTE:** There are 2 separate files listed below

Example of an input files format:

```
2
house
1200.00
755.33
3
2
apartment
600.00
200.00
2
1
```
```
3
house
700.33
100.22
4
2
house
770.94
350.32
2
2
condo
2000.22
1400.00
1
1
```

**Sample inputs file are provided, please add your input to the `input1.txt` and `intput2.txt` files for testing**

### Requirements

* Use the given template and **filename** for your submission.
* You must use functions in an appropriate way
* Your program must read input from two files in the proper format, NOT stdin
* Your program should accept the filenames from the command-line as shown in the example below
* You should use two separate structure arrays
    * These arrays should use the **same** structure definition, because they are storing the same type of data

#### Required Functions

```c
int readProps(FILE *ifp, prop O[]);
double totalIncome(prop O[], int num);
double totalCost(prop O[], int num);
double pricePerBed(prop O[], int num);
int numHouses(prop O[], int num);
```

#### Optional Functions

Additional functions may be used for debugging or while you are developing your program, a useful example is a function to print off some of the properties of one item.

```c
void printProps(prop O[], int num);
```

### Example Output

```
$ ./a.out infile1.txt infile2.txt
Total income Owner1: $1800.00
Total cost Owner2: $1850.54
Average price per bedroom Owner1: $360.00
Average price per bedroom Owner2: $495.93
# of Houses Owner1: 1
# of Houses Owner2: 2
Average price of all properties: $1054.30
```
