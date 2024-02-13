#include <stdio.h>

int main()
{
	// variables for input and output storage
	float wage, tax_rate;
	int hours_worked, rent_cost;

	// prompt the user for values
	printf("Wage: $");
	scanf("%f", &wage);

	printf("Hours: ");
	scanf("%d", &hours_worked);

	printf("Tax rate: ");
	scanf("%f", &tax_rate);

	printf("Rent: $");
	scanf("%d", &rent_cost);

	// calculate results
	float gross_income = wage * hours_worked;
	float tax_paid = tax_rate * gross_income;
	float net_income = gross_income - tax_paid;
	float budget = net_income - (float)rent_cost;

	// print results
	printf("--------------------\n");
	printf("Gross income: $%.2f\n", gross_income);
	printf("Tax: $%.2f\n", tax_paid);
	printf("Net Income: $%.2f\n", net_income);
	printf("Tot. Budget: $%.2f\n", budget);

  return 0;
}
