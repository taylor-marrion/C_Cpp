#include "bst.h"
#include <iostream>
using namespace std;

int main()
{
    node* bst = nullptr;

    insertNode(bst, 50);
    printAscending(bst);
    cout << endl;
    cout << "min: " << findSmallest(bst) << ", max: " << findLargest(bst) << endl << endl;

    insertNode(bst, 25);
    printAscending(bst);
    cout << endl;
    cout << "min: " << findSmallest(bst) << ", max: " << findLargest(bst) << endl << endl;

    insertNode(bst, 75);
    printAscending(bst);
    cout << endl;
    cout << "min: " << findSmallest(bst) << ", max: " << findLargest(bst) << endl << endl;

    insertNode(bst, 10);
    printAscending(bst);
    cout << endl;
    cout << "min: " << findSmallest(bst) << ", max: " << findLargest(bst) << endl << endl;

    insertNode(bst, 40);
    printAscending(bst);
    cout << endl;
    cout << "min: " << findSmallest(bst) << ", max: " << findLargest(bst) << endl << endl;

    insertNode(bst, 60);
    printAscending(bst);
    cout << endl;
    cout << "min: " << findSmallest(bst) << ", max: " << findLargest(bst) << endl << endl;

    insertNode(bst, 100);
    printAscending(bst);
    cout << endl;
    cout << "min: " << findSmallest(bst) << ", max: " << findLargest(bst) << endl << endl;

    int num;
    cout << "Enter a key to search for: ";
    cin >> num;
    node* temp = searchNode(bst, num);

    if (temp == nullptr) {
        cout << "key not found in BST" << endl;
    } else {
        cout << "returned address: " << temp << ", value at returned address: " << temp->data << endl;
    }

    cout << endl;
    printParenthetical(bst);
    cout << endl;

    /******************************************************/
    /*
    cout << "\n\nNow deleting\n\n";

    deleteNode(bst, 100);   // leaf child
    printAscending(bst);
    cout << endl;

    deleteNode(bst, 75);    // has left, no right
    printAscending(bst);
    cout << endl;

    deleteNode(bst, 10);    // leaf child
    printAscending(bst);
    cout << endl;

    deleteNode(bst, 25);    // no left, has right
    printAscending(bst);
    cout << endl;

    deleteNode(bst, 50);    // has left and right children
    printAscending(bst);
    cout << endl;

    cout << "The root value is " << bst->data << endl; //  expecting 40
    */

    return 0;
}
