#include<stdio.h>
#include<stdlib.h>

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

void iniial(){
    Node *n = new_node();
	start = n;
}

void insert(int index, int x) {
	if (count == 0){
		iniial();
		start -> data = x;
		count++;
		return;
	}
	

	Node *n = new_node();
	n -> data = x;

	if (count == 1){
		start -> next = n;
		n -> next = NULL;
		count++;
		return;
	}

	Node *temp = start;
	
	// Index inits from 0, but start is at 0
	// You need to insert the element at one less than the index.
	// Then the element is *AT* the index.
	for(int i =0; i<index-1;i++){
		temp = temp -> next;
	}

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
