[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-9f69c29eadd1a2efcce9672406de9a39573de1bdf5953fef360cfc2c3f7d7205.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=9302334)
# Creating Linked Lists
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

For this assignment you will perform several tasks:

- [ ] 1. Ask the user to enter in the number of nodes for the linked list
- [ ] 2. Generate a list with the # of nodes specified by the user
	* Each node will contain a random number with the range **0-9999**
- [ ] 3. Print out the generated list **(10 per line)**
- [ ] 4. Ask the user to enter in a number
	* Search the list and see if the number is in the list
- [ ] 5. If the number is in the list, change that node's value to a value specified by the user
	* print the list to verify that the specified node was changed
- [ ] 6. Search the list again for a value, if found, delete that node
	* print the list to verify that the node was deleted
- [ ] 7. Search the list and find out if there are any duplicate values in the list and print them out


### Required Functions

_*Functions that have a `P` are functions you are allowed to print in_

```c
/**
 * create a node for your list
 * return a pointer to that node (node *)
 */  
node *makeNode(int val);

/**
 * add a node to the front of the list
 * return new front of list
 */
node *insertFront(node *head, node *new);

/**
 * P: print out the linked list (10 per line)
 */
void printList(node *head);

/**
 * P: given a value, search the list and remove the node with that value
 */
node *deleteNode(node *head, int val);

/**
 * given a new and old value, search the list for the old value and change it to the new one
 */
node *modifyNode(node *head, int old, int new);

/**
 * given a value, searches the list for that value
 * return true or false (or an integer 0 or 1 that you can use as true or false)
 */
int inList(node *head, int val);

/**
 * P: search the linked list looking for any duplicate values in the list
 */
void lookForDupes(node *L);

/**
 * --Optional--
 * returns the number of nodes in a given list
 */
int length(node *L);
```

### Example Output

```
$ ./a.out
How many nodes? 20
8430 2799 4782 9705 7778 7618  473  878 8270 7042 
4739 8414  188 1474 7954 7162 9796 3059 5374  212 

Enter a number to search for: 2799
Found in list
Change to what value? 1
8430    1 4782 9705 7778 7618  473  878 8270 7042 
4739 8414  188 1474 7954 7162 9796 3059 5374  212 

Enter a number to remove: 1
   1 was deleted from the list
8430 4782 9705 7778 7618  473  878 8270 7042 4739 
8414  188 1474 7954 7162 9796 3059 5374  212 

No Dupes Found :(
```

```
$ ./a.out
How many nodes? 15
9564 6561 7377 2904 4080  255 5940 4604 6782 4102 
  29 1955 5023 5536 8641 

Enter a number to search for: 9564
Found in list
Change to what value? 1111
1111 6561 7377 2904 4080  255 5940 4604 6782 4102 
  29 1955 5023 5536 8641 

Enter a number to remove: 0
No node to delete
1111 6561 7377 2904 4080  255 5940 4604 6782 4102 
  29 1955 5023 5536 8641 

No Dupes Found :(
```

```
$ ./a.out
How many nodes? 10
8163  285 4482 4425 5799 6812 7003 5507 1190 6958 

Enter a number to search for: 0
Not in list

Enter a number to remove: 8163
8163 was deleted from the list
 285 4482 4425 5799 6812 7003 5507 1190 6958 

No Dupes Found :(
```

```
$ ./a.out
How many nodes? 5
8667 5337 2002 2216 4007 

Enter a number to search for: 4007
Found in list
Change to what value? 8667
8667 5337 2002 2216 8667 

Enter a number to remove: 2002
2002 was deleted from the list
8667 5337 2216 8667 

Dupe found: 8667
Dupe found: 8667
```
