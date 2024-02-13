#include "ll.h"
#include <iostream>
using namespace std;

int main() {
    node* head = nullptr;
    node* myNode = nullptr;
    int choice, data, index;
    do {
        cout << endl;
        cout << "1.) Insert a new node" << endl;
        cout << "2.) Delete a node" << endl;
        cout << "3.) Search for and return a node" << endl;
        cout << "4.) Exit" << endl << endl;

        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Please enter the value to insert: ";
                cin >> data;
                cout << "Which index would you like to insert at: ";
                cin >> index;
                insertNode(head, index, data);
                break;
            case 2:
                cout << "Please enter the index to delete: ";
                cin >> index;
                deleteNode(head, index);
                break;
            case 3:
                cout << "Please enter a value to search for: ";
                cin >> data;
                myNode = searchNode(head, data);
                if (myNode != nullptr) {
                    cout << myNode->data << " was found at memory address " << myNode << endl;
                }
                break;
            case 4:
                cout << "Goodbye" << endl;
                break;
            default:
                cout << choice << " is an invalid option. Please try again" << endl;
        }

        printList(head);
    } while (choice != 4);

    return 0;
}