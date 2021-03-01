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
	if (index < 0 || count > index){
		printf("%s","Error, insertion not possible \nPlease check index");
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

void display(){
	Node *n = start;
	for (int i=0; i<count; i++){
		printf("%d\n",n->data);
		n  = n -> next;
	}
}

int main(){
	insert(0,100);
	insert(1,10);
	insert(2,20);
	insert(3,30);
	insert(4,40);
	insert(5,50);
	insert(6,60);
	insert(7,70);

	insert(5,55);
	display();
}
