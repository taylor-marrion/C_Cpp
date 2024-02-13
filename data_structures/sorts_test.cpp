#include "sorts.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

void getRandomArray(int arr[], int size);
void copyArray(int src[], int dst[], int size);
void printArray(int arr[], int size);

int main() {

    /* testing with small arrays */
    int size = 20;
    int* arr1 = new int[size];
    int* arr2 = new int[size];
    int* arr3 = new int[size];
    int* arr4 = new int[size];

    getRandomArray(arr1, size);
    copyArray(arr1, arr2, size);
    copyArray(arr1, arr3, size);
    copyArray(arr1, arr4, size);

    printf("%15s", "unsorted: ");
    printArray(arr1, size);

    insertionSort(arr1, size);
    shellSort(arr2, size);
    quickSort(arr3, 0, size-1);
    mergeSort(arr4, 0, size-1);

    printf("%15s", "insertionSort: ");
    printArray(arr1, size);
    printf("%15s", "shellSort: ");
    printArray(arr2, size);
    printf("%15s", "quickSort: ");
    printArray(arr3, size);
    printf("%15s", "mergeSort: ");
    printArray(arr4, size);

    cout << endl << endl << "Now let's work with BIG arrays!" << endl;

    size = 100000;
    cout << "note: \"BIG\" here is " << size << endl;

    int* arr5 = new int[size];
    int* arr6 = new int[size];
    int* arr7 = new int[size];
    int* arr8 = new int[size];

    getRandomArray(arr5, size);
    copyArray(arr5, arr6, size);
    copyArray(arr5, arr7, size);
    copyArray(arr5, arr8, size);

    clock_t start, end;
    double milli_time;

    start = clock();
    insertionSort(arr5, size);
    end = clock();
    milli_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    cout << fixed << setprecision(2) << "Insertion sort CPU time used: " << 1000.0 * (end - start) / CLOCKS_PER_SEC << "ms\n";

    start = clock();
    shellSort(arr6, size);
    end = clock();
    milli_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    cout << fixed << setprecision(2) << "Shell sort CPU time used: " << 1000.0 * (end - start) / CLOCKS_PER_SEC << "ms\n";

    start = clock();
    quickSort(arr7, 0, size-1);
    end = clock();
    milli_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    cout << fixed << setprecision(2) << "Quick sort CPU time used: " << 1000.0 * (end - start) / CLOCKS_PER_SEC << "ms\n";

    // I think this created a stack overlfow on my system so I'm blocking out but peserving the code in case you're testing on a beefier system
    /*
    start = clock();
    mergeSort(arr8, 0, size-1);
    end = clock();
    milli_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    cout << fixed << setprecision(2) << "Merge sort CPU time used: " << 1000.0 * (end - start) / CLOCKS_PER_SEC << "ms\n";
    */

    cout << endl << endl << "What about BIG pre-sorted arrays?" << endl;

    start = clock();
    insertionSort(arr5, size);
    end = clock();
    milli_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    cout << fixed << setprecision(2) << "Insertion sort CPU time used: " << 1000.0 * (end - start) / CLOCKS_PER_SEC << "ms\n";

    start = clock();
    shellSort(arr6, size);
    end = clock();
    milli_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    cout << fixed << setprecision(2) << "Shell sort CPU time used: " << 1000.0 * (end - start) / CLOCKS_PER_SEC << "ms\n";

    start = clock();
    quickSort(arr7, 0, size-1); // my laptop was not beefy enough to actually run this code!!!
    end = clock();
    milli_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    cout << fixed << setprecision(2) << "Quick sort CPU time used: " << 1000.0 * (end - start) / CLOCKS_PER_SEC << "ms\n";

   delete arr1;
   delete arr2;
   delete arr3;
   delete arr4;
   delete arr5;
   delete arr6;
   delete arr7;
   delete arr8;

    return 0;
}

void getRandomArray(int arr[], int size)
{
     int min = 0, max = 1000000; // or whatever bounds you wish
     for(int i = 0; i < size; i++)
     {
          arr[i] = rand()%(max+1 - min) + min;
     }
}

void copyArray(int src[], int dst[], int size)
{
    memcpy(dst, src, size*sizeof(int));
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
