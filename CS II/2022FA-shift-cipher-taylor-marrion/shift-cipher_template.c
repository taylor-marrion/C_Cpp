#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 500

int getUserChoice();
int getShift();
void getString(char buf[]);
void encrypt(char buf[], int shift);
void decrypt(char buf[], int shift);

int main()
{
	int userChoice = 0;
	int shift = 3;	// default
	char buf[SIZE];

	do {
		printf("-------------------------------\n");
		printf("| 1) Change Shift (default 3) |\n");
		printf("| 2) Encrypt a message        |\n");
		printf("| 3) Decrypt a message        |\n");
		printf("| 4) Quit                     |\n");
		printf("-------------------------------\n");
		printf("Option: ");

		userChoice = getUserChoice();

		switch(userChoice) {
			case 1:
				printf("Enter new shift value: ");
				shift = getShift();
				break;
			case 2:
				printf("Input: ");
				encrypt(buf, shift);
				printf("Output: %s\n", buf);
				break;
			case 3:
				printf("Input: ");
				decrypt(buf, shift);
				printf("Output: %s\n", buf);
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid choice! Try again.\n");
				break;
			}
			printf("\n");
		} while (userChoice != 4);

	return 0;
} // end main

int getUserChoice()
{
	int userChoice = 0;
	char dump = 0;

	scanf("%d%c", &userChoice, &dump); // reads '\n' from buffer

	return userChoice;
} // end getUserChoice

int getShift()
{
	int shift = 3;
	char dump = 0;

	scanf("%d%c", &shift, &dump); // reads '\n' from buffer

	return shift;
} // getShift

void getString(char buf[])
{
	fgets(buf, SIZE, stdin);

} // end getString

void encrypt(char buf[], int shift)
{
	getString(buf);
	int len = strlen(buf);

	for(int i = 0; i < len; i++){
		// do not encrypt/decrypt spaces, new lines, or null terminators
		if (buf[i] != ' ' && buf[i] != '\n' && buf[i] != '\0') {
			buf[i] -= shift;
		}
	}
} // end encrypt

void decrypt(char buf[], int shift)
{
	getString(buf);
	int len = strlen(buf);

	for(int i = 0; i < len; i++){
		// do not encrypt/decrypt spaces, new lines, or null terminators
		if (buf[i] != ' ' && buf[i] != '\n' && buf[i] != '\0') {
			buf[i] += shift;
		}
	}
} // end decrypt
