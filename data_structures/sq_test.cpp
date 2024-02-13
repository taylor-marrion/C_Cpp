#include "sq.h"
#include <iostream>
using namespace std;

int main()
{
    node* head = nullptr;
    int choice, data;

    do {
        cout << endl;
        cout << "1.) Push a new node" << endl;
        cout << "2.) pop a node" << endl;
        cout << "3.) Enqueue a new node" << endl;
        cout << "4.) Dequeue a node" << endl;
        cout << "5.) Exit" << endl << endl;

        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Please enter the value to push: ";
                cin >> data;
                push(head, data);
                break;
            case 2:
                cout << "Pop in progress: " << endl;
                pop(head);
                break;
            case 3:
                cout << "Please enter a value to enqueue: ";
                cin >> data;
                enqueue(head, data);
                break;
            case 4:
                cout << "Dequeue in progress: " << endl;
                dequeue(head);
                break;
            case 5:
                cout << "Goodbye" << endl;
                break;
            default:
                cout << choice << " is an invalid option. Please try again" << endl;
        }

        printList(head);
    } while (choice != 5);

    return 0;
}