#include "bst.h"
#include <iostream>
using namespace std;

/*
 * Traversing functions
*/
void preTraverse(node* root)
{
    if (root != nullptr)
    {
        cout << root->data << "  "; // Processing the data
        preTraverse(root->left);
        preTraverse(root->right);
    }
}   // end preTraverse

void printAscending(node* root)
{
    if (root != nullptr)
    {
        printAscending(root->left);
        cout << root->data << "  "; // Processing the data
        printAscending(root->right);
    }
}   // end printAscending

void postTraverse(node* root)
{
    if (root != nullptr)
    {
        postTraverse(root->left);
        postTraverse(root->right);
        cout << root->data << "  "; // Processing the data
    }
}   // end postTraverse

/*
 * Covered in class
*/
void insertNode(node*& root, int key)
{
    if (root == nullptr) {
        root = new node;
        root->data = key;
        root->left = nullptr;
        root->right = nullptr;
    } else {
        if (root->data > key) {
            insertNode(root->left, key);
        } else {
            insertNode(root->right, key);
        }
    }
}   // end insertNode

void deleteNode(node*& root, int key)
{
    if (root == nullptr) {  // key is not found
        cout << key << " is not found in the tree.\n\n";
        return;
    } else {
        if (key < root->data) {
            deleteNode(root->left, key);
        } else if (key > root->data) {
            deleteNode(root->right, key);
        } else {    // key == root->data
            if (root->left == nullptr) {
                // both children are null
                if (root->right == nullptr) {
                    delete root;
                    root = nullptr;
                } else {    // left is nullptr, right is not
                    node* dltPtr = root;
                    root = root->right;
                    delete dltPtr;
                }
            } else {    // left ptr is not null
                // left is not null but right is
                if (root->right == nullptr) {
                    node* dltPtr = root;
                    root = root->left;
                    delete dltPtr;
                } else {
                    // root has 2 children
                    // find largest in left tree
                    node* largestLeft = root->left;
                    while (largestLeft->right != nullptr) {
                        largestLeft = largestLeft->right;
                    }
                    root->data = largestLeft->data;
                    deleteNode(root->left, largestLeft->data);
                }
            }
        }
    }
}   // end deleteNode

/*
 * BST homework functions
*/
void printParenthetical(node* root) // Print the tree using parenthetical notation.
{
    if (root != nullptr) {
        cout << root->data;
        if (root->left != nullptr || root->right != nullptr) {
            cout << " (";
            printParenthetical(root->left);
            cout << " ";
            printParenthetical(root->right);
            cout << ")";
        }
    }
}   // end printParenthetical

node* searchNode(node* root, int key) // Given an integer, return the node pointer for the node that has that integer as an attribute.
{
    // recursive solution
    if (root->data == key) {
        return root;
    }
    /*else if (root == nullptr) {
        return nullptr; // Don't know why this doesn't work
    } */
    else if (key < root->data) {
        if (root->left == nullptr) {
            return nullptr;
        } else {
            return searchNode(root->left, key);
        }
    } else {
        if (root->right == nullptr) {
            return nullptr;
        } else {
            return searchNode(root->right, key);
        }
    }

    // iterative solution
    /*node* temp = root;

    while (temp->data != key && temp != nullptr) {
        if (key < temp->data) {
            if (temp->left == nullptr) {    // I'm not sure why these checks are necessary, I'd think...
                return nullptr;
            } else {
                temp = temp->left;          // this line would cause a return nullptr
            }
        } else {
            if (temp->right == nullptr) {
                return nullptr;
            } else {
                temp = temp->right;
            }
        }
    }

    return temp;*/
}   // end searchNode

int findSmallest(node* root) // returns the smallest value in the BST.
{
    if (root->left == nullptr) {
        return root->data;
    } else {
        return findSmallest(root->left);
    }
}   // end findSmallest

int findLargest(node* root) // returns the smallest value in the BST.
{
    if (root->right == nullptr) {
        return root->data;
    } else {
        return findLargest(root->right);
    }
}   // end findLargest
