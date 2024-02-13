#include <stdio.h>

int main()
{
  // declare variables
  int a, b, result;
  char op;
  // prompt & read first integer
  printf("Enter Value: ");
  scanf("%d", &a);
  // prompt & read operator
  printf("Enter Operator: ");
  scanf(" %c", &op);
  // prompt & read second integer
  printf("Enter Value: ");
  scanf("%d", &b);
  // if or switch to calculate & print result
  switch (op)
  {
	case '+': 	result = a+b;
				break;
	case '-':	result = a-b;
				break;
	case '*':	result = a*b;
				break;
	case '/':
		if (b == 0)
		{
//			printf("Error: cannot divide by zero!\n");
//			result = 0;
		}
		else
		{
			result = a/b;
		}
		break;
  } // end switch

  if (op == '/' && b == 0)
  {
	printf("Invalid operation: divide by zero\n");
  }
  else if (op == '+' || op == '-' || op == '*' | op == '/')
  {
	 printf("%d %c %d is %d\n", a, op, b, result);
  }
  else
  {
	printf("Invalid Operator: %c\n", op);
  }

  return 0;
}
