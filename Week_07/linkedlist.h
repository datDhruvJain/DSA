#ifndef LINKED_LIST
#define LINKED_LIST

/* Create a data type for Node
 * It has Attributes *node and data
 * data stores the data, while *node points to the next node
 */

// Insert an element into the linked list
void insert(int ,int);

// delete Node at the index
void index_delete(int index);
int find(int e);
int get(int index);
void display();
int size();
int isEmpty();

#endif

/* Remeber:
 * The pointers (start and next) hold pointer to the next memory location
 * so start and temp hold the address of the next Node
 * When we do something like temp = temp -> next; we mean that the pointer temp now pointer to the next memory location */
