#include "ll.h"
#include <iostream>
using namespace std;

void insertNode(node*& head, int index, int d)
{
    node* newNode = new node;
    newNode->data = d;
    newNode->next = nullptr;    // NULL

    if (index == 0) {
        newNode->next = head;
        head = newNode;
        return;
    } else {
        node* walker = head;
        int wIndex = 0;
        while(walker != NULL && wIndex < index-1) {
            walker = walker->next;
            wIndex++;
        }

        if (walker == nullptr) {
            cout << "The index is too large, could not insert." << endl;
            delete newNode;
            return;
        } else {
            newNode->next = walker->next;
            walker->next = newNode;
        }
    }
}

void deleteNode(node*& head, int index)
{
    if (head == nullptr) {
        cout << "The list is empty, there's nothing to delete." << endl;
        return;
    }

    if (index == 0) {
        node* dltTemp = head;
        head = head->next;

        delete dltTemp;
        return;
    } else {
        node* walker = head;
        int wIndex = 0;
        while(walker != NULL && wIndex < index-1) {
            walker = walker->next;
            wIndex++;
        }

        if (walker == nullptr) {
            cout << "The index is too large, could not delete." << endl;
            return;
        } else {
            node* dltTemp = walker->next;
            walker->next = walker->next->next;
            delete dltTemp;
        }
    }
}

void printList(node* head)
{
    node* walker = head;
    while (walker != nullptr) {
        cout << walker->data << "   ";
        walker = walker->next;
    }
    cout << endl;
}

node* searchNode(node* head, int key)
{
    node* walker = head;
    while (walker != nullptr && walker->data != key) {
        walker = walker->next;
    }

    if (walker == nullptr) {
        cout << key << " could not be found." << endl;
        return nullptr;
    } else {
        return walker;
    }
}
