#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

// Define a Stucture with Node type
typedef struct node {
	struct node *next;
	int data;
} Node;

Node *start;
int count = 0;

Node* new_node(){
	Node *n; 
	n = (Node*) malloc (sizeof(Node));
	return n;
}


void insert(int index, int x) {
	
	// First we check if the insertion is possible given the Index
	// An Error occurs when we try to insert in negative index
	// Or when we try to insert at an index that does not *Exist*
	if (index < 0 || count < index){
		printf("%s %d\n","Error, insertion not possible \nPlease check index", index);
		return;
	}

	Node *n = new_node();
	n -> data = x;

	if (index == 0){
		if (count != 0){
			n -> next = start -> next;
			start = n;
			count++;
			return;
		}
		else {
			start = n;
			n -> next = NULL;
			count++;
			return;
		}
	}


	Node *temp = start;
	
	// For Linked list, we need to insert AT the index.
	// For that to happen, we need the index of the element before the insertion index
	// That's why we need index-1
	for(int i =0; i<index-1;i++){
		temp = temp -> next;
	}
	
	// This just changes the next variables
	n -> next = temp -> next;
	temp -> next = n;

	count++;

}

void index_delete(int index){
	if (count < 1 || index > count){
		printf("%s", "Error deleting node");
	}
	
	Node *temp = start;

	if (index == 0){
		if (count > 1){
			temp = start;
			start = start -> next;
			//free(temp);
		}

	}

	int i = 0;
	while(i <= index - 1) {
		// Temp and next holds address of node
		// This means that temp stores the address of it's next node
		temp = temp -> next;
		i++;
	}


	temp -> next = (temp -> next) -> next;
	printf("%s %d %s", "Node at index",index,"deleted");
}

void display(){
	Node *n = start;
	printf("\n");
	for (int i=0; i<count-1; i++){
		printf("%d\n",n->data);
		n  = n -> next;
	}
}
