#include <iostream>
#include "heap.h"
using namespace std;

/*
    In reheapDown, if the right child does not exist, 
    then we need to set it's value to something that would always lose (meaning being bigger) to the left child, 
    so we need to change the line to rightValue = leftValue + 1;   -1 point
*/

void insertHeap(int heap[], int key, int &lastIndex)
{
    lastIndex++;
    heap[lastIndex] = key;
    reheapUp(heap, lastIndex);
}   // end insertHeap

void reheapUp_MAX(int heap[], int locIndex)
{
    if (locIndex == 0) {    // Indicates we're at the root. Exit recursion.
        return;
    }
    
    int parentIndex = (locIndex - 1) / 2;

    if (heap[parentIndex] < heap[locIndex]) {
        int temp = heap[parentIndex];
        heap[parentIndex] = heap[locIndex];
        heap[locIndex] = temp;
    }

    reheapUp_MAX(heap, parentIndex);
}   // end reheapUp_MAX

void reheapUp(int heap[], int locIndex)
{
    if (locIndex == 0) {    // Indicates we're at the root. Exit recursion.
        return;
    }
    
    int parentIndex = (locIndex - 1) / 2;

    if (heap[parentIndex] > heap[locIndex]) {
        int temp = heap[parentIndex];
        heap[parentIndex] = heap[locIndex];
        heap[locIndex] = temp;
    }

    reheapUp(heap, parentIndex);
}   // end reheapUp

void deleteHeap(int heap[], int &lastIndex)
{
    if (lastIndex < 0) {
        cout << "Heap is empty." << endl;
        return;
    }

    heap[0] = heap[lastIndex];
    lastIndex--;
    reheapDown(heap, 0, lastIndex);
}   // end deleteHeap

void reheapDown_MAX(int heap[], int locIndex, int lastIndex)
{
    int leftIndex, rightIndex, biggestIndex, leftValue, rightValue;

    leftIndex = (2 * locIndex) + 1;

    if (leftIndex <= lastIndex)
    {
        leftValue = heap[leftIndex];
        rightIndex = leftIndex + 1;
        if (rightIndex <= lastIndex) {
            rightValue = heap[rightIndex];
        } else {
            // have left but no right
            rightValue = leftValue - 1; // always less that leftValue
        }

        if (leftValue > rightValue) {
            biggestIndex = leftIndex;
        } else {
            biggestIndex = rightIndex;
        }

        // check if we should swap
        if (heap[biggestIndex] > heap[locIndex]) {
            int hold = heap[locIndex];
            heap[locIndex] = heap[biggestIndex];
            heap[biggestIndex] = hold;

            reheapDown_MAX(heap, biggestIndex, lastIndex);
        }
    }
}   // end reheapDown_MAX

void reheapDown(int heap[], int locIndex, int lastIndex)
{
    int leftIndex, rightIndex, smallestIndex, leftValue, rightValue;

    leftIndex = (2 * locIndex) + 1;

    if (leftIndex <= lastIndex)
    {
        leftValue = heap[leftIndex];
        rightIndex = leftIndex + 1;
        if (rightIndex <= lastIndex) {
            rightValue = heap[rightIndex];
        } else {
            // have left but no right
            rightValue = leftValue - 1; // always less that leftValue
        }

        if (leftValue < rightValue) {
            smallestIndex = leftIndex;
        } else {
            smallestIndex = rightIndex;
        }

        // check if we should swap
        if (heap[smallestIndex] < heap[locIndex]) {
            int hold = heap[locIndex];
            heap[locIndex] = heap[smallestIndex];
            heap[smallestIndex] = hold;

            reheapDown(heap, smallestIndex, lastIndex);
        }
    }
}   // end reheapDown

/*
 * Converts randomly sorted array into Heap
 */
void heapify(int heap[], int &lastIndex, int size)
{
    for (int i = 0; i < size; i++) {
        reheapUp(heap, i);
        lastIndex++;
    }
}   // end heapify

/*
 * Prints Min Heap in ascending order
 * last 2 ints in heap... why?
 */
void printHeap(int heap[], int lastIndex)
{
    int length = lastIndex+1;
    int * copy = new int(length);
    memcpy(copy, heap, length*(sizeof(int)));

    while (lastIndex >= 0) {
        printf("%d  ", copy[0]); // print root
        deleteHeap(copy, lastIndex);
    }

    // first attempt
    /*while (lastIndex >= 0) {
        printf("%d  ", heap[0]); // print root
        int temp = heap[0]; // swap root w/ lastIndex
        heap[0] = heap[lastIndex];
        heap[lastIndex] = temp;
        lastIndex--;    // decrement lastIndex
        reheapDown(heap, 0, lastIndex);
    }*/

    free(copy);
    copy = nullptr;
    cout << endl;
}   // end printHeap

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}   // end printArray
