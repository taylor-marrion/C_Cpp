#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int size);
void printArr(int arr[], int size);
void swapNum(int *a, int *b);

int main(int argc, char* argv[])
{
	// check valid arguments
	if (argc != 2) {
		printf("Syntax Error: ./<exec> <input file>\n");
		exit(1);
	}

	// open file to read from
	FILE *ifp = NULL;
	ifp = fopen(argv[1], "r");
	if (ifp == NULL) {
		// file did not open correctly
		printf("Could not open file for reading!\n");
		exit(1);
	}

	// get size of array
	int size = 0;
	fscanf(ifp, "%d", &size);

	// dynamically size array
	//int arr[size];	// I didn't like seeing the "expression must have a constant value" error so...
	int *arr = NULL;
	arr = malloc(size * sizeof(int));
	if (arr == NULL){
		printf("Unable to allocate memory for array!\n");
		exit(1);
	}

	// fill array
	for (int i = 0; i < size; i++){
		fscanf(ifp, "%d", &arr[i]);
	}
	// close input file pointer
	fclose(ifp);

	// 1. Print the unsorted array before you run the bubble sort algorithm
	printf("\n** Before Sorting**\n");
	printArr(arr, size);

	// 2. During the bubble sort, you must print out the entire unsorted portion of the array after each comparison (even if a swap was not encountered)
	printf("\n== Bubble Sort ==\n");
	bubbleSort(arr, size);
	printf("== Sorting Completed ==\n");

	// 3. Print out the final sorted array after the bubble sort has completed
	printf("\n** After Sorting**\n");
	printArr(arr, size);

	// free memory allocated to arr
	free(arr);

	return 0;
}

void bubbleSort(int arr[], int size)
{
	for (int i = 0; i < size-1; i ++){
		for (int j = 0; j < size-i-1; j++){
			// -1 because we need a "next" value to comapre to
			// -i because each pass ensures the largest unsorted value is placed at the end of the unsorted portion of the array so we can avoid useless comparisons
			if (arr[j] > arr[j+1]){
				swapNum(&arr[j], &arr[j+1]);
			}
			printArr(arr, size-i);
		}
	}
}

void printArr(int arr[], int size)
{
	for (int i = 0; i < size; i++){
		printf("%3d ", arr[i]);
	}
	printf("\n");
}

void swapNum(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
