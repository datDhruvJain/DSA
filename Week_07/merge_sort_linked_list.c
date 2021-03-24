#include<stdio.h>
#include<stdlib.h>
typedef struct node {
		int data;
		struct node* nxt;
} Node;


Node* head = NULL;
int size = 0;

int error_flag = 0;
	
void add(int index, int data, Node* head){
	if (index > size){
		printf("Error, Cannot insert at index, list too small");
		error_flag = 1;
		return;
	}

	Node* temp = head;
	Node* one = (Node*)malloc(sizeof(Node));
	(*one).data = data;
	one->nxt = NULL;
	
	if (index == 0){
		one->nxt = head;
		head = one;
	}
	
	for(int i=0; i<index; i++){
		temp = temp->nxt;
	}

	one -> nxt = temp -> nxt;
	temp -> nxt = one;

}

int main(){
}
