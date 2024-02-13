#include <iostream>
#include <cstdlib>  // for rand and srand
#include "heap.h"
using namespace std;

int main() {
    int size = 20;
    int heap[20];
    int min = 0, max = 100;
    int newValue;
    int lastIndex = -1;

    for (int i = 0; i < size; i++) {
        newValue = rand()%(max+1 - min) + min;
        heap[i] = newValue;
    }

    cout << "Array of random ints: " << endl;
    printArray(heap, size);

    cout << endl << "Last index BEFORE heapify: " << lastIndex << endl;
    heapify(heap, lastIndex, size);
    cout << "Heap AFTER heapify: " << endl;
    printArray(heap, size);
    cout << "Last index AFTER heapify: " << lastIndex << endl;
    
    cout << endl << "printHeap: " << endl;
    printHeap(heap, lastIndex);

    cout << endl << "Heap AFTER printHeap: " << endl;
    printArray(heap, size);

    /*for (int i = 0; i < size; i++) {
        newValue = rand()%(max+1 - min) + min;
        cout << newValue << " ";
        insertHeap(heap, newValue, lastIndex);

        cout << endl << "Currently in the array: ";
        for (int j = 0; j <= lastIndex; j++) {
            cout << heap[j] << " ";
        }
        cout << endl;
    }*/
    // ending heap: 22 38 65 68 41 72 69 85 96 80

    cout << endl << endl;

    /*for (int i = 0; i < size; i++) {
        cout << heap[0] << " ";
        deleteHeap(heap, lastIndex);

        cout << endl << "Currently in the array: ";
        for (int j = 0; j <= lastIndex; j++) {
            cout << heap[j] << " ";
        }
        cout << endl;
    }*/

    return 0;
}
