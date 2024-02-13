#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROPS 50
#define TYPE_LENGTH 20

/*
	Parameter names in functions can be changed to 
	your desired names
*/

struct prop_def
{
	char type[TYPE_LENGTH];
	double rent;
	double maintenance;
	int num_beds;
	int num_baths;
};
typedef struct prop_def prop;

FILE * getFilePtr(char file[]);
int readProps(FILE *ifp, prop O[]);
void printProps(prop O[], int num);
double totalIncome(prop O[], int num);
double totalCost(prop O[], int num);
double pricePerBed(prop O[], int num);
int numHouses(prop O[], int num);

int main(int argc, char *argv[])
{
	// check valid arguments
	if (argc != 3) {
		printf("Syntax Error: ./<exec> <input file 1> <input file 2>\n");
		exit(1);
	}

	// create arrays to hold properties
	prop prop_list_1[MAX_PROPS];
	prop prop_list_2[MAX_PROPS];

	// read files and close input file pointers
	FILE *ifp_1 = getFilePtr(argv[1]);
	int prop_count_1 = readProps(ifp_1, prop_list_1);
	fclose(ifp_1);

	FILE *ifp_2 = getFilePtr(argv[2]);
	int prop_count_2 = readProps(ifp_2, prop_list_2);
	fclose(ifp_2);

	// Calculate total rental income for Owner1
	double owner1_income = totalIncome(prop_list_1, prop_count_1);
	printf("Total income Owner1: $%.2lf\n", owner1_income);

	// Calculate total maintenance costs for Owner2
	double owner2_maintenance = totalCost(prop_list_2, prop_count_2);
	printf("Total cost Owner2: $%.2lf\n", owner2_maintenance);

	// Average price per bedroom for each owners
	double owner1_pricePerBedroom = pricePerBed(prop_list_1, prop_count_1);
	printf("Average price per bedroom Owner1: $%.2lf\n", owner1_pricePerBedroom);
	double owner2_pricePerBedroom = pricePerBed(prop_list_2, prop_count_2);
	printf("Average price per bedroom Owner2: $%.2lf\n", owner2_pricePerBedroom);

	// Count # of houses owned by each owner
	int owner1_houses = numHouses(prop_list_1, prop_count_1);
	printf("# of Houses Owner1: %d\n", owner1_houses);
	int owner2_houses = numHouses(prop_list_2, prop_count_2);
	printf("# of Houses Owner2: %d\n", owner2_houses);

	// Average price of all properties (combining both owners)
	double owner2_income = totalIncome(prop_list_2, prop_count_2);
	double all_income = owner1_income + owner2_income;
	double all_props = (double) prop_count_1 + prop_count_2;
	double averagePrice = all_income / all_props;
	printf("Average price of all properties: $%.2lf\n", averagePrice);

	return 0;
}

FILE * getFilePtr(char file[])
{
	FILE *ifp = NULL;
	ifp = fopen(file, "r");

	if (ifp == NULL) {
		// file did not open correctly
		printf("Could not open file for reading!\n");
		exit(1);
	}

	return ifp;
}

int readProps(FILE *ifp, prop O[])
{
	// get number of properties
	int prop_count;
	fscanf(ifp, "%d", &prop_count);

	// read file
	for (int i = 0; i < prop_count; i++){
		fscanf(ifp, "%s", &O[i].type);
		fscanf(ifp, "%lf", &O[i].rent);
		fscanf(ifp, "%lf", &O[i].maintenance);
		fscanf(ifp, "%d", &O[i].num_beds);
		fscanf(ifp, "%d", &O[i].num_baths);
	}

	return prop_count;
}

void printProps(prop O[], int num)
{
	for (int i = 0; i < num; i++){
		printf("%s\n", O[i].type);
		printf("%lf\n", O[i].rent);
		printf("%lf\n", O[i].maintenance);
		printf("%d\n", O[i].num_beds);
		printf("%d\n", O[i].num_baths);
	}
}

double totalIncome(prop O[], int num)
{
	double income = 0.0;

	for (int i = 0; i < num; i++){
		income += O[i].rent;
	}

	return income;
}

double totalCost(prop O[], int num)
{
	double cost = 0.0;

	for (int i = 0; i < num; i++){
		cost += O[i].maintenance;
	}

	return cost;
}

double pricePerBed(prop O[], int num)
{
	double cost = 0.0;
	int bedrooms = 0;

	for (int i = 0; i < num; i++){
		cost += O[i].rent;
		bedrooms += O[i].num_beds;
	}

	return (cost/bedrooms);
}

int numHouses(prop O[], int num)
{
	int houses = 0;

	for (int i = 0; i < num; i++){
		if (strcmp(O[i].type, "house") == 0){
			houses++;
		}
	}

	return houses;
}
