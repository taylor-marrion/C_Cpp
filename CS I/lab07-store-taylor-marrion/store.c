#include <stdio.h>

#define NUMS 5	// number of items on order form

void cleanup()
{
	while (getchar() != '\n');
}	// end cleanup

int main()
{
	// greet user
	char name[10];
	printf("Enter your name: ");
	scanf("%9s",name);
	cleanup();
	printf("Welcome %s!\n", name);

	// declare array to hold items
	int items[NUMS] = {[0 ... (NUMS -1)] = 1};	// initialize as all available
	// Designated Initializers - https://gcc.gnu.org/onlinedocs/gcc/Designated-Inits.html
	int choice = 0;

	do
	{
		// display order form
		printf("\nSelect an item to buy: \n");

		for (int i = 0; i < NUMS; i++)
		{
			if (items[i])
				printf("%3d) available\n", i);
			else
				printf("%3d) sold out\n", i);
		}

		// prompt for user input
		printf("Item (-1 to quit): ");
		scanf("%d", &choice);

		// process order
		if (choice >= 0 && choice < NUMS)
		{
			if (items[choice])
				items[choice] = 0;
			else
				printf("***Item %d is sold out!\n", choice);
		}
		else if (choice != -1)
		{
			printf("***Item %d doesn't exist\n", choice);
		}

	} while (choice != -1);

	// farewell to user
	printf("\nThanks for shopping with us, %s\n", name);
        return 0;
}	// end main
