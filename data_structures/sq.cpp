#include "sq.h"
#include <iostream>
using namespace std;

void push(node*& head, int d)   // 'd' is an integer to store in the data attribute of the node being pushed onto the stack.
{
    // head is the newest node, at "top" of stack
    node* newNode = new node;
    newNode->data = d;
    newNode->next = head;   // points to "top" of stack
    head = newNode;         // head now points to newNode

    return;
}

void pop(node*& head)   // Simply removes the latest node pushed onto the stack.
{
    // head is the newest node, at "top" of stack
    if (head == nullptr) {
        cout << "The stack is empty, there's nothing to pop." << endl;
        return;
    }

    node* dltTemp = head;   // stores memory address to head
    head = head->next;      // points head to next node
    delete dltTemp;         // "frees" memory allocated to old head

    return;
}

void enqueue(node*& head, int d)    // 'd' is an integer to store in the data attribute of the node being enqueued.
{
    // head is the oldest node, newNode will be placed at "tail" end of queue
    node* newNode = new node;
    newNode->data = d;
    newNode->next = nullptr;

    if (head == nullptr) {  // empty stack
        head = newNode;
        return;
    }

    node* walker = head;

    while (walker->next != nullptr) {   // loop until end of queue
        walker = walker->next;
    }
    walker->next = newNode;             // replace null with ptr to newNode

    return;
}

void dequeue(node*& head)   // Simply removes the oldest node still in the queue.
{
    // head is the oldest node
    if (head == nullptr) {
        cout << "The queue is empty, there's nothing to dequeue." << endl;
        return;
    }

    node* dltTemp = head;   // stores memory address to head
    head = head->next;      // points head to next node
    delete dltTemp;         // "frees" memory allocated to old head

    return;
}

void printList(node* head)  // Prints out the list on a single line (values separated by a space or two, and creates a newline after the list is printed).
{
    node* walker = head;
    while (walker != nullptr) {
        cout << walker->data << "   ";
        walker = walker->next;
    }
    cout << endl;
}
