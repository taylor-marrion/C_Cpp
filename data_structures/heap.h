#ifndef HEAP_H
#define HEAP_H

/*
 * covered in class
 */
void insertHeap(int heap[], int key, int &lastIndex);
void reheapUp_MAX(int heap[], int locIndex);                    // MAX Heap
void deleteHeap(int heap[], int &lastIndex);
void reheapDown_MAX(int heap[], int locIndex, int lastIndex);   // MAX Heap

/*
 * homework
 */
void reheapUp(int heap[], int locIndex);                        // MIN Heap
void reheapDown(int heap[], int locIndex, int lastIndex);       // MIN Heap
void heapify(int heap[], int &lastIndex, int size);
void printHeap(int heap[], int lastIndex);

/*
 * utility functions
 */
void printArray(int arr[], int size);

#endif