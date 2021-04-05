// Write a C/C++/Java program to implement a stack using linear singly linked list. 
// Your program should read input from the file testcaseForStack.txt. 
// Each line in the file begins with either 1 or 2. 1 stands for push and 2 stands for pop. 
// Those lines beginning with 1 further contains the details of the record you are supposed to push. 
// The record structure remains the same as the student record in the first part. 
// To be specific, you are supposed to implement the following functions.
// struct node*pop(struct node**top)//removes the topmost node from the stack and
// returns the address of the same, returns NULL if in case the stack is empty are supposed to push.
// int isEmpty()//returns 1 if the stack is empty (top=NULL) and 0 otherwise
// void push(struct node**top,struct node*temp)//temp is the address of the node that you
//  Note that the stack never gets full and hence push never fails. 
// Note that you have to create node using malloc function, fill in data that you read from the file and then invoke push. 
// On each successful pop, print the data associated with the node that you popped from your main function and free up the corresponding node memory 
// (print an error message if in case the stack was empty). In addition, make sure that you declare top as a local variable in your main function and pass reference to top variable (&top) both to push and pop functions so as to update the top variable from within the function if required.

#include<iostream>
class Node{
    public:
    int data;
    Node* next = NULL;
};

class linkedlist{
    Node* head = NULL;
    
    bool err_flag = 0;
    public:

	// Count stores the number of elements present in the linkedlist.
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
			for(int i=1;i<count-1;i++){
				temp = temp -> next;
			}
			int data = (temp->next) -> data;
			free(temp->next);
			temp -> next = NULL;
			count--;
			return data;

		}

		// case that first element is deleted
		if (index == 0 && head != NULL){
			
			Node* temp = head;
			head = head -> next;

			int data = temp -> data;
			free(temp);
			count--;
			return data;
		}

		// case that any random middle eleemnt in deleted
		for(int i=0; i<index-1; i++){
			temp = temp -> next;
		}

		int data = (temp->next) -> data;
		temp -> next = (temp -> next) -> next;
		count--;
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

class llstack{
	linkedlist ll;
	public:

	int isEmpty(){
		if (ll.count == 0){
			return 1;
		}
		
		return 0;
	}

	int pop(){
		 int data = ll.deleteNode(ll.count-1);
		 return data;
	}

	void push(int data){
		ll.insertNode(ll.count, data);
	}
	
};

int main(){
	llstack stk;
	stk.push(10);
	stk.push(20);
	//stk.push(30);
	//stk.push(40);
	printf("%d",stk.pop());
	printf("%d",stk.pop());
}