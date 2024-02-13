#include <stdio.h>
#include <stdlib.h>

typedef struct node_def node;

struct node_def
{
	int val;
	node *next;
};

// global variables
/**
 * Use this global variable for the top of your stack.
 * 
 * In this case we are using a global variable purely
 * for ease of use in the assignment.
 */
node *stack = NULL;

void push(int x);
void pop();
int top();
void printStack();
void toBinary(int x);

int main()
{
	// 1. Ask the user to enter in the integer to be converted to binary.
	int num;
	printf("Enter an integer: ");
	scanf("%d", &num);

	// 2. Convert decimal to binary using a stack with a singly linked list.
	toBinary(num);

	return 0;
}

// puts a number on the stack
void push(int x)
{
	// create new node
	node *top = malloc(sizeof(node));
	top->val = x;
	top->next = stack;

	// point stack to new node
	stack = top;
}

// takes a number off the stack
void pop()
{
	node * tmp = stack;	// save pointer to deallocate memory

	stack = stack->next;	// 2nd node is now "on top"

	free(tmp);	// free memory allocated to old top of stack
}

// returns the value of the number on the top of the stack
int top()
{
	return stack->val;
}

// prints the contents of the stack (top to bottom)
void printStack()
{
	int bit;
	while (stack != NULL){
		bit = top();
		printf("%2d ", bit);
		pop(stack);
	}
	printf("\n");
}

// prints off the binary version of a decimal number
void toBinary(int x)
{
	int r;	// remainder

	while (x > 0){
		r = x % 2;
		x = x / 2;

		push(r);
	}
	printStack();
}
