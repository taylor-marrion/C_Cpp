#include <stdio.h>

int main()
{
  // get input from user
  int size;

  // get input from user
  do
  {
	printf("Size of Tree: ");
	scanf("%d", &size);

	// print body of tree
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size*2-1; col++)
		{
			if (col < size - row -1 || col > size + row -1)
			{
				printf(" ");
			}
			else
			{
				printf("#");
			}
		}
		printf("\n");
	}

	// print trunk of tree
	for (int i = 0; i < size*2-1; i++)
	{
		if (i == size-1)
		{
			printf("#");
		}
		else
		{
			printf(" ");
		}
	}
	printf("\n");

  } while (size >= 1);

  return 0;
}
