#ifndef SORTS_H
#define SORTS_H

void insertionSort(int arr[], int size);
void shellSort(int arr[], int size);
void quickSort(int arr[], int p, int r);
int partition(int arr[], int p, int r);
void mergeSort(int arr[], int p, int r);
void merge(int arr[], int p, int q, int r);

#endif