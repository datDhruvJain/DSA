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
		Node n;
		head = &n;
		size++;
	}

	linkedlist(int data){
		Node n = {data, NULL};
		head = &n;
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
			temp = temp->next;

		}

		Node* n = (Node*) malloc(sizeof(Node));
		n -> data = data;
		n -> next = temp -> next;
		temp -> next = n;

	}

	void printLinkedList(){
		Node *temp = head;
		if (size == 0){return;}
		while(temp -> next != NULL){
			std::cout << temp -> data << std::endl;
		}
	}

};

int main(){
	linkedlist ll = linkedlist();
	ll.add(0,5);
	ll.printLinkedList();
}
