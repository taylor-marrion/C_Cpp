![Open in Codespaces](https://classroom.github.com/assets/open-in-codespaces-abfff4d4e15f9e1bd8274d9a39a0befe03a0632bb0f153d0ec72ff541cedbe34.svg)
# Points and Graphs
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

**You MUST use the given template!**

For this program you will be printing of a grid of 10 points (x, y).  You will be reading the points from a file, and printing the points and grid to a file.

Both files will be specified in the command-line arguments.

**Your output in the file must match mine EXACTLY.**

The grid will be 20x20, which means all points will fall within the range `0 <= x <= 19`

You will also be tasked to find the 2 points that are closest to each other.  These 2 points will be marked by a different character in your grid.  You will read the points from the file into an array of structures.  One structure item should contain an x-value and a y-value.

### Input file format

The input file will contain **exactly** 10 points in `x y` format.  The first value is `x` and the second is `y`.

Example of input file format:
```
7 19
11 5
15 11
4 10
1 8
10 4
2 5
14 12
10 9
12 4
```

### Requirements

**Follow all instructions in the template.**

Required Functions:
```c
void fill(char str[], point2d P[]);
int getdist(point2d p, point2d q);
void closest(point2d P[], int G[2*N][2*N]);
void grid(point2d P[], int G[2*N][2*N]);
void printpoints(char str[], point2d P[]);
void printgridxy(char str[], int G[2*N][2*N]);
```

### Example Terminal Output

```
$ ./a.out points.txt output.txt
```

### Example Output File

```
0: ( 7, 19)
1: (11,  5)
2: (15, 11)
3: ( 4, 10)
4: ( 1,  8)
5: (10,  4)
6: ( 2,  5)
7: (14, 12)
8: (10,  9)
9: (12,  4)
--------------------------------------------------
              *                         
                                        
                                        
                                        
                                        
                                        
                                        
                            *           
                              *         
        *                               
                    *                   
  *                                     
                                        
                                        
    *                 X                 
                    X   *               
                                        
                                        
                                        
                                        
--------------------------------------------------
```

### Example Graph

**This graph is for readability and example purposes only!  You don't have to produce this output.**

Note how the spacing is set so that the graph looks more square.  The x and y axis values are for demonstration purposes and should not be included in the output of your program.

```
   --------------------------------------------------
19:              *                         
18:                                        
17:                                        
16:                                        
15:                                        
14:                                        
13:                                        
12:                            *           
11:                              *         
10:        *                               
 9:                    *                   
 8:  *                                     
 7:                                        
 6:                                        
 5:    *                 X                 
 4:                    X   *               
 3:                                        
 2:                                        
 1:                                        
 0:                                        
   --------------------------------------------------
   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
```
