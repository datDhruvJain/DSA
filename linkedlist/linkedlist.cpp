#include<iostream>
#include<cstdlib>

class linkedlist{
	typedef struct node {
		int data;
		struct node* next;
	} Node;

	Node* head;
	int size = 0;

	bool error_flag = 0;

	Node* new_node(){
		Node* n = (Node*) malloc(sizeof(Node));
		return n;
	}
	
	public:

	void insert(int index, int data){
		if (index > size){
			std::cout << "Error, Cannot insert at index, list too small" << std::endl;
			error_flag = 1;
			return;
		}

		if (index == 0){
			if(size == 0){
				head = new_node();
				head -> data = data;
				head -> next = NULL;
			}
			
			else {
				Node* n = new_node();
				n -> data = data;
				n -> next = head;
				head = n;
			}

			size++;
			return;
		}

		Node* temp = head;
		
		for(int i=0; i<index-1; i++){
			temp = temp->next;

		}

		Node* n = new_node();
		n -> data = data;
		n -> next = temp -> next;
		temp -> next = n;
		
		size++;
		return;

	}

	void printLinkedList(){
		Node *temp = head;
		if (size == 0){return;}

		for(int i=0;i<size;i++){
			std::cout << temp -> data << std::endl;
			temp = temp -> next;
		}
	}

};

int main(){
	linkedlist ll;
	ll.insert(0,1);
	ll.insert(1,2);
	ll.insert(1,3);
	ll.insert(2,4);
	ll.insert(3,5);
	ll.insert(4,6);

	ll.printLinkedList();
}
