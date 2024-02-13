[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-9f69c29eadd1a2efcce9672406de9a39573de1bdf5953fef360cfc2c3f7d7205.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=9366966)
# Train Stations
## Points: 40

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

This program will import train station and train route data from several input files. You will use many topics covered throughout the entirety of the course, including 2D arrays, structures, and linked lists to store the data from the input files. Once the data has been read in properly, you will construct a menu with various options, these options will ask the user for input, make calculations on that input, and display the results to the user. Please pay special attention to the message in the example output both when a user enters valid and invalid data.

You need to complete the following operations on the data:
1. Read in the two data files specified in the command-line arguments
    1. The first file contains the stations data, this will be read into a 2D character array where the index is the station number
    2. The second file contains the trains data, this will be read into a singly linked list, the structure that will be used for the list is defined in the template
2. Develop a menu to support all options below (in the order listed below)
    1. For a station number, print the name
    2. For a name, print the station number
    3. Determine if there is a direct route from station A to station B
    4. Of all train routes, find the route with the shortest time and display all information for that route (station #, station name, start time (24-hour), end time (24-hour))
    5. List all of the train routes that have a start time on or after the time specified by the user **(this MUST be a 24-hour formatted time (ex. 1754))**
        * Include the time specified in the search (i.e. if 1200 is specified, make sure to include trains that start at 720)

You should use the following menu and options, with the provided formatting:

```
------------------------------------------------------
             Welcome to the Train Program
------------------------------------------------------

   0)  Quit
   1)  Find a station number
   2)  Find a station name
   3)  Is there a direct path between 2 stations?
   4)  Find shortest time on train for a direct trip
   5)  List all routes after a specified time (hhmm)

Please pick an option: 
```


### Input file format

There are 2 input files, the first contains stations data and the second contains trains data. In the example shown below, filenames are provided. **Note that the filenames will NOT be predetermined.** You will need to use command-line arguments to get the files and they need to be in the correct order (stations file, then trains file).

The input files do not have a number specifying the number of lines/trains/stations in the file; you must determine when to stop reading when all the data has been gathered.

In the `stations` file each line will have the following format:

```
S# SN
S#: station number [0..99]
SN: station name [string] max length 25 (no spaces will be used)
```

**Note:** The station names will be max length of 25 including the `\0`, so 24 characters plus the `\0` for a total of 25.

**Note:** The stations may not be in order from 0-N, meaning stations may be listed 2, 3, 1, 0 rather than in order 0, 1, 2, 3. However, there will not be any gaps, meaning if there is a station 3, there must be station 0, 1, 2.

In the `trains` file each line will have the following format:

```
DS# AS# DT AT
DS#: Depart station number   0-99
AS#: Arrival station number  0-99
DT : Departure time in range 0-1439
AT : Arrival time in range   0-1439
```

**No trains run past midnight**

**Note:** The range of the time, this is not standard 24-hour format. This format using the total number of minutes in a day (i.e. 60 mins * 24 hours = 1440 mins). You will need to convert this to 24-hour format (e.g. 00:00 through 23:59)


#### Example of an input files format:

`stations.dat`
```
0 Madison
1 Brookings
2 Sioux_Falls
3 Fargo
4 Watertown
5 Sioux_City
6 Bismarck
7 Pierre
8 West_Fargo
9 Rapid_City
10 Mitchell
11 Box_Elder
12 Plainsville
13 Hot_Springs
14 Hot_Valley
15 Hot_River
16 Hotsville
17 Hot_Lake
18 Hot_Town
19 Hot_Village
```

`trains.dat`
```
0 1 1200 1210
0 2 400 408
0 3 500 507
1 0 1220 1230
1 2 600 604
1 5 900 910
2 4 110 114
3 0 610 631
3 8 625 635
3 9 915 940
4 5 1110 1120
5 9 300 310
5 1 320 330
6 0 715 720
8 6 930 934
9 3 700 726
9 5 330 345
9 10 1300 1310
10 9 1320 1335
2 3 610 614
```

**Sample inputs file are provided, please add your input to the `stations.dat` and `trains.dat` files for testing**

### Requirements

* Use the given template and **filename** for your submission.
* You must use functions in an appropriate way
* Your program must read input from two files in the proper format, NOT stdin
* Your program should accept the filenames from the command-line as shown in the example below
* You should handle cases when no data is returned
* You should either handle invalid menu options or quit the program, it should not loop infinitely

#### Required Functions

Please see the template provided for detailed descriptions and instructions for each function listed below.

```c
/**
 * Input functions
 */
void read_file_stations(FILE *file, char stations[][MAX_STATION_LENGTH]);
train_route *read_file_trains(FILE *file, train_route *routes);
train_route *make_route(int origin_station, int dest_station, int start_time, int end_time);
train_route *add_route(train_route *routes, train_route *new_route);

/**
 * Calculation functions
 */
bool direct_route(train_route *routes, int origin_station, int dest_station);
train_route *shortest_time(train_route *routes);
void list_routes(train_route *routes, char stations[][MAX_STATION_LENGTH], int time);
int find_station_number(int num_stations, char stations[][MAX_STATION_LENGTH], char search_str[MAX_STATION_LENGTH]);
void find_station_name(char stations[][MAX_STATION_LENGTH], int station_num, char station_name[MAX_STATION_LENGTH]);
```

#### Optional Functions

```c
/**
 * Optional functions
 */
int convert_to_24(int minute_time);
int convert_from_24(int time_24);
int line_count(FILE *file);
```

### Example Output

```
$ ./a.out ../stations.dat ../trains.dat


------------------------------------------------------
             Welcome to the Train Program
------------------------------------------------------

   0)  Quit
   1)  Find a station number
   2)  Find a station name
   3)  Is there a direct path between 2 stations?
   4)  Find shortest time on train for a direct trip
   5)  List all routes after a specified time (hhmm)

Please pick an option: 1
Enter a station name: test
 test station does not exist.
 Make sure there isn't a typing error.



------------------------------------------------------
             Welcome to the Train Program
------------------------------------------------------

   0)  Quit
   1)  Find a station number
   2)  Find a station name
   3)  Is there a direct path between 2 stations?
   4)  Find shortest time on train for a direct trip
   5)  List all routes after a specified time (hhmm)

Please pick an option: 1
Enter a station name: Sioux_Falls
 Sioux_Falls is station number 2



------------------------------------------------------
             Welcome to the Train Program
------------------------------------------------------

   0)  Quit
   1)  Find a station number
   2)  Find a station name
   3)  Is there a direct path between 2 stations?
   4)  Find shortest time on train for a direct trip
   5)  List all routes after a specified time (hhmm)

Please pick an option: 2
Enter a station #: 22
Station does not exist



------------------------------------------------------
             Welcome to the Train Program
------------------------------------------------------

   0)  Quit
   1)  Find a station number
   2)  Find a station name
   3)  Is there a direct path between 2 stations?
   4)  Find shortest time on train for a direct trip
   5)  List all routes after a specified time (hhmm)

Please pick an option: 2
Enter a station #: 3
Station 3 is Fargo



------------------------------------------------------
             Welcome to the Train Program
------------------------------------------------------

   0)  Quit
   1)  Find a station number
   2)  Find a station name
   3)  Is there a direct path between 2 stations?
   4)  Find shortest time on train for a direct trip
   5)  List all routes after a specified time (hhmm)

Please pick an option: 3
Enter origin station number: 0
Enter destination station number: 4
There is NOT a direct path between station 0 and station 4



------------------------------------------------------
             Welcome to the Train Program
------------------------------------------------------

   0)  Quit
   1)  Find a station number
   2)  Find a station name
   3)  Is there a direct path between 2 stations?
   4)  Find shortest time on train for a direct trip
   5)  List all routes after a specified time (hhmm)

Please pick an option: 3
Enter origin station number: 0
Enter destination station number: 3
There is a direct path between station 0 and station 3



------------------------------------------------------
             Welcome to the Train Program
------------------------------------------------------

   0)  Quit
   1)  Find a station number
   2)  Find a station name
   3)  Is there a direct path between 2 stations?
   4)  Find shortest time on train for a direct trip
   5)  List all routes after a specified time (hhmm)

Please pick an option: 4
The shortest route is from
  2: Sioux_Falls @ 1010
     to
  3: Fargo @ 1014



------------------------------------------------------
             Welcome to the Train Program
------------------------------------------------------

   0)  Quit
   1)  Find a station number
   2)  Find a station name
   3)  Is there a direct path between 2 stations?
   4)  Find shortest time on train for a direct trip
   5)  List all routes after a specified time (hhmm)

Please pick an option: 5
Enter earliest starting time in 24-hour format (hhmm): 1200
10: Mitchell       @ 2200  to   9: Rapid_City     @ 2215
 9: Rapid_City     @ 2140  to  10: Mitchell       @ 2150
 8: West_Fargo     @ 1530  to   6: Bismarck       @ 1534
 4: Watertown      @ 1830  to   5: Sioux_City     @ 1840
 3: Fargo          @ 1515  to   9: Rapid_City     @ 1540
 1: Brookings      @ 1500  to   5: Sioux_City     @ 1510
 1: Brookings      @ 2020  to   0: Madison        @ 2030
 0: Madison        @ 2000  to   1: Brookings      @ 2010



------------------------------------------------------
             Welcome to the Train Program
------------------------------------------------------

   0)  Quit
   1)  Find a station number
   2)  Find a station name
   3)  Is there a direct path between 2 stations?
   4)  Find shortest time on train for a direct trip
   5)  List all routes after a specified time (hhmm)

Please pick an option: 0
```

```
$ ./a.out ../stations.dat ../trains.dat


------------------------------------------------------
             Welcome to the Train Program
------------------------------------------------------

   0)  Quit
   1)  Find a station number
   2)  Find a station name
   3)  Is there a direct path between 2 stations?
   4)  Find shortest time on train for a direct trip
   5)  List all routes after a specified time (hhmm)

Please pick an option: 7
```
