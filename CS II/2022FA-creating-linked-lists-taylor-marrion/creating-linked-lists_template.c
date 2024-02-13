#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node_def node;
struct node_def
{
    int val;
    node *next;
};

node *makeNode(int val);
node *insertFront(node *head, node *new);
void printList(node *head);
node *deleteNode(node *head, int val);
node *modifyNode(node *head, int old, int new);
int inList(node *head, int val);
void lookForDupes(node *L);
// int length(node *L);

int main()
{
    // initialize nodes
    node *head = NULL;
    node *tmp = NULL;
    // seed random values
    srand(time(0));
    int r;
    // create ints for user input
    int user_num;
    int new_num;

    // get number of nodes from user
    int num_nodes;
    printf("How many nodes? "); // 1. Ask the user to enter in the number of nodes for the linked list
    scanf("%d", &num_nodes);

    // 2. Generate a list with the # of nodes specified by the user
    for (int i = 0; i < num_nodes; i++){
        r = rand() % 10000;
        tmp = makeNode(r);  // 2b. Each node will contain a random number with the range 0-9999
        head = insertFront(head, tmp);
    }

    // 3. Print out the generated list (10 per line)
    printList(head);

    // 4. Ask the user to enter in a number
    printf("\nEnter a number to search for: ");
    scanf("%d", &user_num);

    // 4b. Search the list and see if the number is in the list
    if (inList(head, user_num)){
        printf("Found in list\n");
        // 5. If the number is in the list, change that node's value to a value specified by the user
        printf("Change to what value? ");
        scanf("%d", &new_num);
        modifyNode(head, user_num, new_num);
        printList(head);    // 5b. print the list to verify that the specified node was changed
    } else {
        printf("Not in list\n");
    }

    // 6. Search the list again for a value, if found, delete that node
    printf("\nEnter a number to remove: ");
    scanf("%d", &user_num);
    if (inList(head, user_num)){
        head = deleteNode(head, user_num);
        printf("%5d was deleted from the list\n", user_num);
        printList(head);    // 6b. print the list to verify that the node was deleted
    } else {
        printf("No node to delete\n");
    }

    // 7. Search the list and find out if there are any duplicate values in the list and print them out
    printf("\n");
    lookForDupes(head);

    // free up memory
    free(head);
    free(tmp);

	return 0;
}

/**
 * create a node for your list
 * return a pointer to that node (node *)
 */  
node *makeNode(int val)
{
    node *new = malloc(sizeof(node));
    new->val = val;
    new->next = NULL;
    
    return new;
}

/**
 * add a node to the front of the list
 * return new front of list
 */
node *insertFront(node *head, node *new)
{
    new->next = head;
    return new;
}

/**
 * P: print out the linked list (10 per line)
 */
void printList(node *head)
{
    while (head != NULL){
        for (int i = 0; i < 10; i++){
            if (head == NULL){
                break;
            } else {
                printf("%5d", head->val);
                head = head->next;
            }
        }
        printf("\n");
    }
}

/**
 * P: given a value, search the list and remove the node with that value
 */
node *deleteNode(node *head, int val)
{
    // this function deletes only the first node containing val, repeating values in the list will not be deleted
    // check if head is node to be deleted
    if (head != NULL && head->val == val){
        head = head->next;
        return head;
    }

    node *current = head;
    node *next = head->next;
    // cannot be head, so start with node after head
    while (next != NULL && next->val != val){
        current = current->next;
        next = next->next;
    }

    // must have reached end of list or correct node to exit while loop
    if (next->val == val){
        current->next = next->next; // skip next
    } else {
        next->next == NULL;
    }

    free(current);
    free(next);

    return head;
}

/**
 * given a new and old value, search the list for the old value and change it to the new one
 */
node *modifyNode(node *head, int old, int new)
{
    while (head != NULL){
        if (head->val == old){
            head->val = new;
            break;
        }
        head = head->next;
    }
    return head;    // order of list hasn't changed, not sure why this isn't void return type
}

/**
 * given a value, searches the list for that value
 * return true or false (or an integer 0 or 1 that you can use as true or false)
 */
int inList(node *head, int val)
{
    int result = 0;

    if (head != NULL){
        while (head->val != val && head->next != NULL){
            head = head->next;
        }
        if (head->val == val){
            result = 1;
        }
    }

    return result;
}

/**
 * P: search the linked list looking for any duplicate values in the list
 */
void lookForDupes(node *L)
{
    int found = 0;
    node *tmp = L->next;

    while (tmp->next != NULL){
        while (tmp->next != NULL){
            if (L->val == tmp->val){
                found++;
                printf("Dupe found: %5d\n", L->val);
                printf("Dupe found: %5d\n", tmp->val);
            }
            tmp = tmp->next;
        }
        L = L->next;
        tmp = L->next;
    }
    free(tmp);
    if (found == 0){
        printf("No Dupes Found :(\n");
    }
}

/**
 * --Optional--
 * returns the number of nodes in a given list
 */
// int length(node *L)
// {

// }
