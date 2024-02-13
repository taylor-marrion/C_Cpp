// CSC 250
// student template

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int findMin(int arr[], int size);
int findMax(int arr[], int size);
int findSum(int arr[], int size);
// Add additional function protoypes here
void fillArrWithRand(int arr[], int size);
int findIndex(int value, int arr[], int size);
void printArr(int arr[], int size);


int main()
{
    /**
     * HINT: Use dynamic array allocation using the int arr[size]; notation
     */
    // declare variables
    int size, max, max_pos, min, min_pos, avg, sum;

    // create array from user input
     printf("Enter an integer: ");
     scanf("%d", &size);
     int arr[size];

     // fill array with random ints [0-1000]
     fillArrWithRand(arr, size);

     // find data about array
     max = findMax(arr, size);
     max_pos = findIndex(max, arr, size);
     min = findMin(arr, size);
     min_pos = findIndex(min, arr, size);
     sum = findSum(arr, size);
     avg = sum/size;

     // print data about array
     printf("max: %6d pos: %6d\n", max, max_pos);
     printf("min: %6d pos: %6d\n", min, min_pos);
     printf("avg: %6d\n", avg);
     printf("sum: %6d\n", sum);

     printf("\n");

     // print array
     printArr(arr, size);

    return 0;
} // end main

int findMin(int arr[], int size)
{
    // Add code below and return the min
    // Do not print in this function
    int min = INT_MAX;
    for(int i = 0; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
} // end findMin

int findMax(int arr[], int size)
{
    // Add code below and return the max
    // Do not print in this function
    int max = INT_MIN;
    for(int i = 0; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
} // end findMax

int findSum(int arr[], int size)
{
    // Add code below and return the sum
    // Do not print in this function
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
} // end findSum

// Add addition functions here

/* fill array with random int values */
void fillArrWithRand(int arr[], int size){
    srand(time(0));
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 1001;
    }
} // end fillArrWithRand

/* find first index of value in array
    return -1 if not found */
int findIndex(int value, int arr[], int size){
    int pos = -1;
    for(int i = 0; i < size; i++){
        if(arr[i] == value){
            return i;
        }
    }
    return pos;
} // end findIndex

/* print entire array */
void printArr(int arr[], int size){
    printf(" Pos  :   Val\n");
    printf("-------------\n");
    for(int i = 0; i < size; i++){
        printf("%5d : %5d\n", i, arr[i]);
    }
} // end printArr
