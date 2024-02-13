#ifndef STACK_H
#define STACK_H
#include "vertex.h"

struct Stack
{
	int count;
	Node* top;
};

void initStack(Stack& s);
void deleteStack(Stack& s);
bool pushStack(Stack& s, Vertex* dataIn);
bool popStack(Stack& s, Vertex*& dataOut);
bool stackTop(Stack& s, Vertex*& dataOut);
bool emptyStack(Stack& s);
bool fullStack(Stack& s);
int stackCount(Stack& s);

#endif