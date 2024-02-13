#include <stdio.h>

float average(int a, int b, int c);
char grade(int score);
void printByTwo(int start, int stop);
int area(int width, int height);

int main()
{
	int a, b, c;
	printf("Enter three integers to get the average: ");
	scanf("%d%d%d", &a, &b, &c);
	float avg = average(a, b, c);
	printf("The average of %d, %d, and %d is %f\n", a, b, c, avg);

	int score;
	printf("Enter a score to receive a grade: ");
	scanf("%d", &score);
	char letter = grade(score);
	printf("A score of %d provides a grade of %c\n", score, letter);

	int start, stop;
	printf("Enter a start number: ");
	scanf("%d", &start);
	printf("Enter a stop number: ");
	scanf("%d", &stop);
	printByTwo(start, stop);

	int width, height;
	printf("Enter a rectangle width: ");
	scanf("%d", &width);
	printf("Enter a rectangle height: ");
	scanf("%d", &height);
	int rec_area = area(width, height);
	printf("A rectangle of width %d and width %d has an area of %d\n", width, height, rec_area);

	return 0;
}

float average(int a, int b, int c)
{
	return (a + b + c) / 3.0;
} // end average

char grade(int score)
{
	char grade = 'F';
	if (score >= 92)
		grade = 'A';
	else if (score >= 84)
		grade = 'B';
	else if (score >= 76)
		grade = 'C';
	else if (score >= 68)
		grade = 'D';

	return grade;
} // end grade

void printByTwo(int start, int stop)
{
	printf("Printing by 2 from %d to %d\n", start, stop);
	for (int i = start; i <= stop; i+=2)
	{
		printf("%d ", i);
	}
	printf("\n");
} // end printByTwo

int area(int width, int height)
{
	return (width * height);
} // end area
