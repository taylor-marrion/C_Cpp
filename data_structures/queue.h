#ifndef QUEUE_H
#define QUEUE_H
#include "vertex.h"

struct Queue
{
	Node* front;
	int count;
	Node* rear;
};

void initQueue(Queue& q);
void deleteQueue(Queue& q);
bool dequeue(Queue& q, Vertex*& dataOut);
bool enqueue(Queue& q, Vertex* dataIn);
bool queueFront(Queue& q, Vertex*& dataOut);
bool queueRear(Queue& q, Vertex*& dataOut);
int queueCount(Queue& q);
bool emptyQueue(Queue& q);
bool fullQueue(Queue& q);

#endif