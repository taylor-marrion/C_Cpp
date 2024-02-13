#include <stdio.h>

int main()
{
	// read and store product ID
	char idOne, idTwo, idThree;
	printf("Product ID: ");
	scanf(" %c%c%c", &idOne, &idTwo, &idThree);

	// read and store product price
	float price;
	printf("Price: ");
	scanf("%f", &price);

	// read and store product quality score
	char quality;
	printf("Quality: ");
	scanf(" %c", &quality);

	// read and store available quantity of product
	int quantity;
	printf("Quantity: ");
	scanf("%d", &quantity);

	printf("There are %d %c%c%c of quality score %c available at a price of $%.2f each\n", quantity, idOne, idTwo, idThree, quality, price);

  return 0;
}
