#include <stdio.h>
#include <string.h>

#define SIZE 999	// max string length

char getLeet(char c);	// function placeholder

int main()
{
	// prompt user for input
	char input[SIZE];
	printf("Enter a phrase to convert: ");
	fgets(input, SIZE, stdin);

	// new string to preserve original
	char leet[strlen(input)];

	// convert to leetspeak
	for (int i = 0; i < strlen(input); i++)
	{
	// The original plan was to create a function that returned a string but that led me into pointers which we haven't covered so this function works char by char
		leet[i] = getLeet(input[i]);
	}

	// print l337$p3@k
	printf("Your converted string is: %s", leet);

        return 0;
} // end main

char getLeet(char c)
{
	char result;

	switch(c)
	{
		case 'A':
		case 'a': result = '@';
			break;
		case 'I':
		case 'i': result = '!';
			break;
		case 'E':
		case 'e': result = '3';
			break;
		case '0': result = 'O';
			break;
		case 'O': result = '0';
			break;
		case 'S':
		case 's': result = '$';
			break;
		case 'T':
		case 't': result = '7';
			break;
		default : result = c;

	}

	return result;
} // end getLeet
