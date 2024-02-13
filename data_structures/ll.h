#ifndef LL_H
#define LL_H

struct node
{
    int data;
    struct node* next;
};

void insertNode(node*& head, int index, int d);
void deleteNode(node*& head, int index);
void printList(node* head);
node* searchNode(node* head, int key);

#endif