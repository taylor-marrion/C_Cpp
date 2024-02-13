![Open in Codespaces](https://classroom.github.com/assets/open-in-codespaces-abfff4d4e15f9e1bd8274d9a39a0befe03a0632bb0f153d0ec72ff541cedbe34.svg)
# Inventory System
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

This assignment will make use of `structs` and reading from a file.  You would be creating a sort of database-like system that will be keeping track of the inventory of a store.  Each item in the inventory should be its own `struct` item, and you should use a `struct` array to store the entirety of the inventory.


The goal of this assignment is to have you read in this information from a file and save it into an array of structures which represent the inventory items.

**A max of 500 items will be read in from the file.**

Once the data is read into your program, your program must then perform the following tasks and print them off to the screen

1. Calculate the total value of your inventory (this means $)
	* The value is the total of all items
	* The value should be a decimal value as shown in the examples
2. Find total number of items in inventory
3. Tell me which items need to be ordered (one per line)
	* _An item needs to be ordered if the quantity of that item is less than 10_


### Input file format

The input file will have the following format:

```
1st line: signifies the number of inventory items
2nd line: states the name of the item (50 character max length)
3rd line: indicates the quantity of that item currently available
4th line: indicates the price of the item
5th line: is the id of the item
6th line: is the date of the last order

Lines 2-6 will repeat for as many items specified in line 1
```

Example of input file format:

```
1
coke
15
1.59
12657435
12/12/2014
```


```
3
coke
15
1.59
12657435
12/12/2014
pepsi
9
1.49
12547543
12/10/2014
sprite
7
1.59
12657437
12/09/2014
```

**A sample input file is provided, please add your input to the `input.txt` file for testing**

You should create other input files of your own using the appropriate format to test your program with larger data sizes.


### Requirements

* Use the given template and **filename** for your submission.
* You must use functions in an appropriate way
* Your program must read input from a file in the proper format, NOT stdin
* Your program should accept the filename from the command-line as shown in the example below
	* You should use appropriate error checking


#### Required Functions

```c
int readFile(char filename[], struct inventory_item inventory_list[]);
int getTotalItems(struct inventory_item inventory_list[], int count);
double getTotalVal(struct inventory_item inventory_list[], int count);
```

#### Optional Functions

Additional functions may be used for debugging or while you are developing your program, a useful example is a function to print off some of the properties of one item.

```c
void printItem(struct inventory_item item)
{
	// Print off properties of one individual item
}
```


### Example Output

```
$ ./a.out infile.txt
Total inventory value: $48.39
Total inventory quantity: 31
Items that need to be ordered:
    pepsi
    sprite
```
