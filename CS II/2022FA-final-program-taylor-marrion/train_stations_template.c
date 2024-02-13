#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STATION_LENGTH (25)

//int num_stations;   // cheaty way of getting size of 2d array in find_station_name

/**
 * Struction definition for train routes
 * This is provided
 * Do not make changes to the struction definition
 */
typedef struct train_route_def
{
    int origin_station;
    int dest_station;
    int start_time;
    int end_time;
    int duration;
    struct train_route_def *next;
} train_route;

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

/**
 * Optional functions
 */
int convert_to_24(int minute_time);
int convert_from_24(int time_24);
int line_count(FILE *file);
FILE * getFilePtr(char file[]);
int printMenu();
void printList(train_route *head);
void printRoute(train_route *route);

int main(int argc, char *argv[])
{
    // check valid arguments
	if (argc != 3) {
		printf("Syntax Error: ./<exec> <input file 1> <input file 2>\n");
		exit(1);
	}

    int num_stations;
    char (*stations)[MAX_STATION_LENGTH] = NULL;
    train_route *routes = NULL;
    int choice;
    int station_num;
    char station_name[MAX_STATION_LENGTH];
    int origin_station;
    int dest_station;
    train_route *shortest_route = NULL;
    int time;

    // 1. Read in the two data files specified in the command-line arguments
    // 1 i) first file contains the stations data, read into a 2D character array where the index is the station number
	FILE *ifp_stations = getFilePtr(argv[1]);
        num_stations = line_count(ifp_stations);
        stations = malloc((num_stations * MAX_STATION_LENGTH) * sizeof(char));
        if (stations == NULL){
		    printf("Unable to allocate memory for array!\n");
		    exit(1);
	    }
	    read_file_stations(ifp_stations, stations);
	fclose(ifp_stations);

    // 1 ii) second file contains the trains data, this will be read into a singly linked list of train_route
	FILE *ifp_trains = getFilePtr(argv[2]);
        routes = read_file_trains(ifp_trains, routes);
	fclose(ifp_trains);

    // 2) Develop a menu to support all options below
    do {
        choice = printMenu();

        switch(choice){
            case 1:
                // 2 ii) For a name, print the station number
                printf("Enter a station name: ");
                scanf("%s", station_name);
                station_num = find_station_number(num_stations, stations, station_name);
                if (station_num >= 0){
                    printf(" %s is station number %d\n", station_name, station_num);
                } else {
                    printf(" %s station does not exist.\n", station_name);
                    printf(" Make sure there isn't a typing error.\n");
                }
                break;
            case 2:
                // 2 i) For a station number, print the name
                printf("Enter a station #: ");
                scanf("%d", &station_num);
                if (station_num < 0 || station_num >= num_stations){
                    printf("Station does not exist\n");
                } else {
                    find_station_name(stations, station_num, station_name);
                    printf("Station %d is %s\n", station_num, station_name);
                }
                break;
            case 3:
                // 2 iii) Determine if there is a direct route from station A to station B
                printf("Enter origin station number: ");
                scanf("%d", &origin_station);
                printf("Enter destination station number: ");
                scanf("%d", &dest_station);
                if (direct_route(routes, origin_station, dest_station)){
                    printf("There is a direct path between station %d and station %d\n", origin_station, dest_station);
                } else {
                    printf("There is NOT a direct path between station %d and station %d\n", origin_station, dest_station);
                }
                break;
            case 4:
                // 2 iv) find route with shortest time and display all information for that route (station #, station name, start time (24-hour), end time (24-hour))
                printf("The shortest route is from\n");
                shortest_route = shortest_time(routes);
                printf(" %2d: %s @ %d\n", shortest_route->origin_station, stations[shortest_route->origin_station], convert_to_24(shortest_route->start_time));
                printf("     to\n");
                printf(" %2d: %s @ %d\n", shortest_route->dest_station, stations[shortest_route->dest_station], convert_to_24(shortest_route->end_time));
                break;
            case 5:
                // 2 v) List all train routes that have a start time on or after time specified by user (24-hour formatted time (ex. 1754))
                printf("Enter earliest starting time in 24-hour format (hhmm): ");
                scanf("%d", &time);
                list_routes(routes, stations, time);
                break;
            default:
                if (choice != 0)
                    printf("Error! Please select a valid option\n\n");
        }
    } while (choice != 0);

    return 0;
}

/***********************
 * Required Functions *
 **********************/

/**
 * Input functions
 */
void read_file_stations(FILE *file, char stations[][MAX_STATION_LENGTH])
{
    /**
     * Use this function to read in the data from the stations file
     * 
     * The file pointer should be passed in, not the character filename,
     * the file should already be opened in main(), and you should close it
     * in main()
     */
    int num = 0;
    while (!feof(file)){
        num++;
        fscanf(file, "%d", &num);
        fscanf(file, "%s", stations[num]);
    }
}

train_route *read_file_trains(FILE *file, train_route *routes)
{
    /**
     * Use this function as the primary call to read in the data from 
     * the trains data file
     * 
     * The file pointer should be passed in, not the character filename,
     * the file should already be opened in main(), and you should close it
     * in main()
     * 
     * This function will perform the scanning from the input file
     * 
     * This function will call additional functions that will build up
     * your linked list
     * 
     * This function should return the head pointer of the linked list
     * back to main()
     */
    int orig, dest, start, end;
    int num = 0;

    while (!feof(file)){
        fscanf(file, "%d", &orig);
        fscanf(file, "%d", &dest);
        fscanf(file, "%d", &start);
        fscanf(file, "%d", &end);

        train_route *tmp = make_route(orig, dest, start, end);
        routes = add_route(routes, tmp);
        num++;
    }
    return routes;
}

train_route *make_route(int origin_station, int dest_station, int start_time, int end_time)
{
    /**
     * Use this function to create a new route (node) for the linked list
     * 
     * Note that this function simply creates the route (node), it does not
     * add it to the list yet
     * 
     * Use the parameters to fill the route (node)
     * 
     * Remember to calculation the duration in this step
     * 
     * Remember to set ->next to NULL in this step
     * 
     * This function should return the pointer of the newly created
     * route (node) back to main()
     */
    train_route *new = malloc(sizeof(train_route));
    new->origin_station = origin_station;
    new->dest_station = dest_station;
    new->start_time = start_time;
    new->end_time = end_time;
    new->duration = end_time - start_time;
    new->next = NULL;

    return new;
}

train_route *add_route(train_route *routes, train_route *new_route)
{
    /**
     * Use this function to add the newly created route (node) to the linked
     * list, you may choose to insert in the front or the end of the list
     * 
     * Note that this function simple inserts the route (node), it does not
     * create the node or allocate space
     * 
     * This function should return the head pointer of the linked list
     * back to main()
     */
    new_route->next = routes;
    return new_route;
}

/**
 * Calculation functions
 */

bool direct_route(train_route *routes, int origin_station, int dest_station)
{
    /**
     * This function searches the routes linked list to find a route that matches
     * the origin and destination stations that were passed in
     * 
     * Return true or false if the route is found or not found
     */
    bool result = false;

    train_route *tmp = routes;

    while (tmp != NULL){
        if (origin_station == tmp->origin_station && dest_station == tmp->dest_station){
            return true;
        }
        tmp = tmp->next;
    }
    return result;
}

train_route *shortest_time(train_route *routes)
{
    /**
     * This function searches the routes linked list to find the route with the 
     * shortest duration
     * 
     * Return the pointer to the route (node) with the shortest duration
     */
    int min = 1440;
    train_route *shortest = NULL;
    train_route *tmp = routes;

    while (tmp != NULL){
        if (tmp->end_time - tmp->start_time < min){
            min = tmp->end_time - tmp->start_time;
            shortest = tmp;
        }
        tmp = tmp->next;
    }
    return shortest;
}

void list_routes(train_route *routes, char stations[][MAX_STATION_LENGTH], int time)
{
    /**
     * This function searches the routes linked list to find any route that has
     * a starting time that starts on or after the `time` that is passed in
     * 
     * This function will print out the data for each matching route inside 
     * this function
     * 
     * Make sure the data printed out matches the example output in the README
     */
    time = convert_from_24(time);
    train_route *tmp = routes;
    while (tmp != NULL){
        if (tmp->start_time > time){
            printf("%2d: %-14s @ %-5d to  %2d: %-14s @ %-5d\n", tmp->origin_station, stations[tmp->origin_station], convert_to_24(tmp->start_time), tmp->dest_station, stations[tmp->dest_station], convert_to_24(tmp->end_time));
        }
        tmp = tmp->next;
    }
}

int find_station_number(int num_stations, char stations[][MAX_STATION_LENGTH], char search_str[MAX_STATION_LENGTH])
{
    /**
     * This function searches the stations array to find the number (index) of the 
     * station that matches the search string that was passed in
     * 
     * Return the index that matches the search string to main()
     * 
     * You may want to consider returning -1 if a match was not found
     */
    int num = -1;   // assume station doesn't exist

    for (int i = 0; i < num_stations; i++){
        if (strcmp(search_str, stations[i]) == 0){
            return i;
        }
    }
    return num;
}

void find_station_name(char stations[][MAX_STATION_LENGTH], int station_num, char station_name[MAX_STATION_LENGTH])
{
    /**
     * This function searches the stations array at the index provided (station_num)
     * to find the name of the station
     * 
     * Note the station_name parameter will be used for storing the result since
     * strings cannot be retured in C, you will need to use strncpy() to copy the 
     * name from the stations array into the station_name array
     */

    strncpy(station_name, "\0", MAX_STATION_LENGTH);    // reset string: without this, chars left in string after name lookups
    strncpy(station_name, stations[station_num], strlen(stations[station_num]));
}



/**
 * Optional Functions
 */

int convert_to_24(int minute_time)
{
    /**
     * You may find it beneficial to make a function that converts time
     * from the minute time (0-1439) to standard 24-hour time (0-2359)
     * 
     * Return the integer in 24-hour time
     */
    int hours = minute_time / 60 * 100;
    int minutes = minute_time % 60;

    return hours + minutes;
}

int convert_from_24(int time_24)
{
    /**
     * You may find it beneficial to make a function that converts time
     * from standard 24-hour time (0-2359) to the minute time (0-1439)
     * 
     * Return the integer in minute time
     */
    int hours = time_24 / 100 * 60;
    int minutes = time_24 % 100;
    
    return hours + minutes;
}

int line_count(FILE *file)
{
    /**
     * You may find it beneficial to have a function that counts the lines
     * in a file since this is not given
     * 
     * Reset the file pointer back to the beginning since you'll likely call
     * this function before reading the data in
     * 
     * You may find the rewind() function useful:
     * https://www.cplusplus.com/reference/cstdio/rewind/
     * 
     * Return the number of lines back to main()
     */
    int num = 0;
    char str[MAX_STATION_LENGTH];

    while (!feof(file)){
        num++;
        fgets(str, MAX_STATION_LENGTH, file);
    }
    rewind(file);   // reset file pointer to beginning of file

    return num;
}

FILE * getFilePtr(char file[])
{
	FILE *ifp = NULL;
	ifp = fopen(file, "r");

	if (ifp == NULL) {
		// file did not open correctly
		printf("Could not open file \"%s\" for reading!\n", file);
		exit(1);
	}

	return ifp;
}

int printMenu()
{
    int choice;
    printf("\n\n");
    printf("------------------------------------------------------\n");
    printf("             Welcome to the Train Program\n");
    printf("------------------------------------------------------\n");
    printf("\n");
    printf("   0)  Quit\n");
    printf("   1)  Find a station number\n");
    printf("   2)  Find a station name\n");
    printf("   3)  Is there a direct path between 2 stations?\n");
    printf("   4)  Find shortest time on train for a direct trip\n");
    printf("   5)  List all routes after a specified time (hhmm)\n");
    printf("\n");
    printf("Please pick an option: ");
    scanf ("%d", &choice);

    return choice;
}

void printList(train_route *head)
{
    train_route *tmp = head;
    while (tmp != NULL){
        printf("orig: %5d; next: %x\n", tmp->origin_station, tmp->next);
        tmp = tmp->next;
    }
}
