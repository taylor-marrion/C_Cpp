#include "sorts.h"
#include <iostream>
using namespace std;

void insertionSort(int arr[], int size)
{
    int current, hold, walker;

    for (current = 1; current < size; current++)
    {
        hold = arr[current];

        for (walker = current - 1; walker >= 0 && hold < arr[walker]; walker--)
        {
            arr[walker + 1] = arr[walker];
        }
        arr[walker + 1] = hold;
    }
}

void shellSort(int arr[], int size)
{
    int incre, current, hold, walker;
    int last = size - 1;

    for(incre = last / 2; incre != 0; incre /= 2)
    {
        for(current = incre; current <= last; current++)
        {
            hold = arr[current];

            for (walker = current - incre; walker >= 0 && hold < arr[walker]; walker -= incre)
            {
                arr[walker + incre] = arr[walker];
            }

            arr[walker + incre] = hold;
        }
    }
}

void quickSort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

int partition(int arr[], int p, int r)
{
    int x = arr[r];
    int i = p - 1;
    int j, temp;

    for (j = p; j < r; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp;
    
    return i +=1;
}

void mergeSort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = (p+r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

void merge(int arr[], int p, int q, int r)
{

    int i, j;
    int n1 = q - p + 1; // size of L
    int n2 = r - q;     // size of R

    int* L = new int[n1];
    int* R = new int[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[p+i];
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = arr[q+j+1];
    }

    i = 0;
    j = 0;
    
    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i += 1;
        } else 
        {
            arr[k] = R[j];
            j += 1;
        }
    }
}
