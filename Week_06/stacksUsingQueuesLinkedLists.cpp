#include<iostream>
class Node{
	public:
		int data;
		Node* next = NULL;
};

class LinkedList{
	Node* head = NULL;

	bool err_flag = 0;
	public:
	int count = 0;

	// Insert an element at given index
	void insertNode(int index, int data){
		if (index>count){
			std::cout << "Error, cannot insert at index. Index out of bounds" << std::endl;
			err_flag = 1;
			return;
		}

		// Create a new node
		Node* n = new Node;
		n -> data = data;

		if(index == 0){            
			if(head == NULL){
				n -> data = data;
				n -> next = NULL;
				head = n;
				count++;
				return;
			}

			n -> next = head;
			head = n;
			count++;
			return;
		}

		Node* temp;
		temp = head;

		for(int i=0; i<index - 1; i++){
			temp = temp -> next;
		}

		temp -> next = n;

		count++;
	}

	int deleteNode(int index){
		Node* temp = head;
		
		// case that last element is deleted
		if (index == count -1){
			for(int i=0;i<count-2;i++){
				temp = temp -> next;
			}
			int data = (temp->next) -> data;
			free(temp->next);
			temp -> next = NULL;
			return data;

		}

		// case that first element is deleted
		if (index == 0 && head != NULL){
			
			Node* temp = head;
			head = head -> next;

			int data = temp -> data;
			free(temp);
			return data;
		}

		// case that any random middle eleemnt in deleted
		for(int i=0; i<index-1; i++){
			temp = temp -> next;
		}

		int data = (temp->next) -> data;
		temp -> next = (temp -> next) -> next;
		return data;
	}

	void display(){
		if (count == 0){
			std::cout << "Linked list empty" << std::endl;
			return;
		}

		Node* temp = head;
		while(temp -> next != NULL){
			std::cout << temp->data << " ";
			temp = temp -> next;
		}
		std::cout << temp->data << std::endl;
	} 

	bool isEmpty(){
		if(count==0){
			return true;
		}
		return false;
	}
};

class stack {
	Node* top;
	LinkedList ll;
	public:
	int size = ll.count;

	bool err_flag = false;
	
	void push(int data){
		ll.insertNode(0, data);
	}

	int pop(){
		if(ll.count == 0){
			std::cout << "Error stack empty" << std::endl;
			err_flag = true;
			return -1;
		}
		return ll.deleteNode(0);
	}

	void display(){
		ll.display();
	}

};
// --- main function to test ---

class queue{
	stack s1, s2;
	void stackToQueueHelper(){
		for(int i=0;i<s2.size-1; i++){
			s1.push(s2.pop());
		}
	}
	
	public:

	void menu(){
		bool cont = true;
		char choice;
		int num;
		while(cont){
			std::cout << "Please enter (E)nqueue/(D)equeue/e(X)it" << std::endl;
			std::cin >> choice;
			switch(choice){
				case 'E': {
					std::cout << "Enter value to enqueue" <<std::endl;
					std::cin >> num;
					s2.push(num);
					break;
				}

				case 'D': {
					for(int i=0;i<s2.size-1; i++){
						s1.push(s2.pop());
					}
					std::cout << s1.pop() << std::endl;
					break;
				}

				case 'X':{
					cont = false;
					break;
				}
			}
		}
	}
};

int main(){
	queue q;
	q.menu();
}