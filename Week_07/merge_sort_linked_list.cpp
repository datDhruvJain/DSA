/* Write a program to implement merge sort using linked lists (you should use the same set of input test cases).
 * We have learned a procedure to merge two sorted listsinto one (Tutorial 6). 
 * Your function mergeSort() should take a head pointer of a linked list as input, call a function split(), 
 * that would split the list into two and would return a head pointer to the second list, 
 * recursively sort both and then merge.
*/
#include<iostream>

class linkedlist{
	typedef struct node {
		int data;
		struct node* next;
	} Node;

	Node* head;
	int size = 0;

	bool error_flag = 0;
	
	public:
	linkedlist(){
		Node n = {NULL, NULL};
		head = &n;
		size++;
	}

	linkedlist(int data){
		Node n = {data, NULL};
		size++;
	}
	
	void add(int index, int data){
		if (index > size){
			std::cout << "Error, Cannot insert at index, list too small" << std::endl;
			error_flag = 1;
		}

		Node* temp = head;

		//while((temp<-next) != NULL){
		//	temp = temp<-next;
		//}
		
		for(int i=0; i<index; i++){
			temp = temp<-next;
		}

		

	}

};
