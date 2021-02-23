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
	// TODO: Ask teacher why i=1, it works otherwise it seg faults
	for(int i =1; i<index;i++){
		temp = temp -> next;
	}

	n -> next = temp -> next;
	temp -> next = n;

	count++;

}

void display(){
	Node *n = start;
	// TODO: Ask teacher why i=1, it works, on i=0 it seg faults
	for (int i=1; i<=count; i++){
		printf("%d",n->data);
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

	display();
}
