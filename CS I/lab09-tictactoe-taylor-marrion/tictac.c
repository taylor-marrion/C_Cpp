#include <stdio.h>

// You can use these prototypes if you like
char gameOver(char b[3][3]);
void print(char b[3][3]);
int available(char b[3][3], int r, int c);

int main()
{
	char board[3][3] = {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	};

	int row, col, valid;
	int player = 0;

	// loop until game is won or board is full
	char winner = ' ';
	while (winner == ' ')
	{
		// let player select position
		if (player == 0)
			printf("Enter a row and column for x: ");
		else
			printf("Enter a row and column for o: ");
		scanf("%d %d", &row, &col);
		// validate position
		valid = available(board, row, col);
		if (valid == 1)
		{
			if (player == 0)
			{
				player = 1;
				board[row][col] = 'x';
			}
			else
			{
				player = 0;
				board[row][col] = 'o';
			}

			print(board);
			// check if win occured
			winner = gameOver(board);
		}
		else if (valid == -1)
		{
			printf("You've entered an invalid row or column - please use 0-2 for both\n");
		}
		else
		{
			printf("That space is occupied - try again\n");
		}
	}

	if (winner != 's')
		printf("The player using %c won the game\n", winner);
	else
		printf("There is no winner - stalemate\n");

	return 0;
} // end main

char gameOver(char b[3][3])
{
	// horizontal line
	for (int i = 0; i < 3; i++)
	{
		if (b[i][0] == b[i][1] && b[i][0] == b[i][2] && b[i][0] != ' ')
			return b[i][0];
	}
	// vertical line
	for (int i = 0; i < 3; i++)
	{
		if (b[0][i] == b[1][i] && b[0][i] == b[2][i] && b[0][i] != ' ')
			return b[0][i];
	}

	// diagonal line
	if (b[0][0] == b[1][1] && b[0][0] == b[2][2] && b[0][0] != ' ')
		return b[0][0];
	if (b[0][2] == b[1][1] && b[0][2] == b[2][0] && b[0][2] != ' ')
		return b[0][2];

	// check stalemate
	int stale = 1;
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			if (b[r][c] == ' ')
				stale = 0;
		}
	}
	if (stale ==1)
		return 's';

	// if no cases met
	return ' ';
} // end gameOver

void print(char b[3][3])
{
	printf("%c|%c|%c\n", b[0][0], b[0][1], b[0][2]);
	printf("-+-+-\n");
	printf("%c|%c|%c\n", b[1][0], b[1][1], b[1][2]);
	printf("-+-+-\n");
	printf("%c|%c|%c\n", b[2][0], b[2][1], b[2][2]);

} // end print

int available(char b[3][3], int r, int c)
{
	// invalid
	if (r < 0 || r > 2 || c < 0 || c > 2)
		return -1;
	// available
	else if (b[r][c] == ' ')
		return 1;
	// available
	else
		return 0;
} // end available
