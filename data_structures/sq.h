#ifndef LL_H
#define LL_H

struct node
{
    int data;
    struct node* next;
};

void push(node*& head, int d);    // 'd' is an integer to store in the data attribute of the node being pushed onto the stack.
void pop(node*& head);               // Simply removes the latest node pushed onto the stack.
void enqueue(node*& head, int d);   // 'd' is an integer to store in the data attribute of the node being enqueued.
void dequeue(node*& head);       // Simply removes the oldest node still in the queue.
void printList(node* head);          // Prints out the list on a single line (values separated by a space or two, and creates a newline after the list is printed).

#endif