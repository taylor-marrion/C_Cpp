#ifndef BST_H
#define BST_H

struct node
{
    int data;
    struct node* left;
    struct node* right;
    
};

/*
 * Traversing functions
*/
void preTraverse(node* root);
//void inTraverse(node* root);  // replaced by printAscending
void postTraverse(node* root);

/*
 * Covered in class
*/
void insertNode(node*& root, int key);
void deleteNode(node*& root, int key);
void printAscending(node* root);

/*
 * BST homework functions
*/
void printParenthetical(node* root); // Print the tree using parenthetical notation.
node* searchNode(node* root, int key); // Given an integer, return the node pointer for the node that has that integer as an attribute.
int findSmallest(node* root); // returns the smallest value in the BST.
int findLargest(node* root); // returns the smallest value in the BST.

#endif