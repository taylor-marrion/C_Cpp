#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 500
#define NAME_LENGTH 10

struct inventory_item
{
	// Fill in the required attributes
	char name[NAME_LENGTH];
	int qty;
	double price;
	int id;
	char order_date[11];

};

int readFile(char filename[], struct inventory_item inventory_list[]);
int getTotalItems(struct inventory_item inventory_list[], int count);
double getTotalVal(struct inventory_item inventory_list[], int count);
void printLowStock(struct inventory_item inventory_list[], int count);

void printItem(struct inventory_item item)
{
	// This is an optional function
	printf("%s\n", item.name);
	printf("%d\n", item.qty);
	printf("%lf\n", item.price);
	printf("%d\n", item.id);
	printf("%s\n", item.order_date);

	return;
}

int main(int argc, char *argv[])
{
	// check valid arguments
	if (argc != 2) {
		printf("Syntax Error: ./<exec> <input file>\n");
		exit(1);
	}

	char* filename = NULL;
	filename = (char*)malloc(strlen(argv[1]) * sizeof(char));
	strcpy(filename, argv[1]);

	// create array to hold inventory
	struct inventory_item inventory_list[MAX_ITEMS];

	// read file
	int item_count = readFile(filename, inventory_list);

	// get total value
	double total_value = getTotalVal(inventory_list, item_count);

	// get total quantity
	int total_qty = getTotalItems(inventory_list, item_count);

	printf("Total inventory value: $%.2lf\n", total_value);
	printf("Total inventory quantity: %d\n", total_qty);
	printf("Items that need to be ordered:\n");

	// print items that need to be ordered
	printLowStock(inventory_list, item_count);

	return 0;
}

int readFile(char filename[], struct inventory_item inventory_list[])
{
	FILE *ifp = NULL;
	ifp = fopen(filename, "r");

	if (ifp == NULL) {
		// file did not open correctly
		printf("Could not open file for reading!\n");
		exit(1);
	}

	int item_count;
	fscanf(ifp, "%d", &item_count);

	// read file
	for (int i = 0; i < item_count; i++){
		fscanf(ifp, "%s", &inventory_list[i].name);
		fscanf(ifp, "%d", &inventory_list[i].qty);
		fscanf(ifp, "%lf", &inventory_list[i].price);
		fscanf(ifp, "%d", &inventory_list[i].id);
		fscanf(ifp, "%s", &inventory_list[i].order_date);
	}

	// close input file pointer
	fclose(ifp);

	return item_count;
}

int getTotalItems(struct inventory_item inventory_list[], int count)
{
	int num = 0;
	for (int i = 0; i < count; i++){
		num += (inventory_list[i].qty);
	}
	return num;
}

double getTotalVal(struct inventory_item inventory_list[], int count)
{
	double value = 0.0;
	for (int i = 0; i < count; i++){
		value += (inventory_list[i].qty * inventory_list[i].price);
	}
	return value;
}

void printLowStock(struct inventory_item inventory_list[], int count){
	for (int i = 0; i < count; i++){
		if(inventory_list[i].qty < 10){
			printf("\t%s\n", inventory_list[i].name);
		}
	}
}