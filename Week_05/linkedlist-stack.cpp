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
    char rollNo[20];
	char emailId[35];
	char lecture[3];
	char tutorial[3];
	char practical[3];
    Node* next = NULL;
};

class linkedliststk{
    //Node* head = NULL;
    
    bool err_flag = 0;
    public:

	// Count stores the number of elements present in the linkedlist.
    int count = 0;

    // Insert an element at given index
    void pushNode(Node** head, Node* node){
        
        // If the list doesn't exist, create the listi
        // We use *head because we are passing a pointer to the pointer, so we first need to dereference the head pointer
        if(*head==NULL){
            *head = node;
            count++;
            return;
        } 

        node -> next = *head;
        *head = node;
    }
    
	Node* popNode(Node** head){
		
        Node* temp = *head;
        *head = (**head).next;
        count--;
        return temp;
	}

    void display(Node** head){
        if (count == 0){
            std::cout << "Linked list empty" << std::endl;
            return;
        }

        Node* temp = *head;
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

int main(){
    linkedliststk stk;
    Node* top = NULL;
    Node n;
    n.data = 12;

    stk.pushNode(&top, &n);
    stk.display(&top);
    stk.popNode(&top);
    stk.display(&top);

	int op;

   FILE*fp1; 
   fp1=fopen("testcaseForStack.txt","r");

   for (i=0;i<138;i++){
		fscanf(fp1,"%d", &op);

		if(op==1){

		}
   }
   strcpy(ptr->rollNo, buffer.rollNo);
   strcpy(ptr->emailId, buffer.emailId);
   strcpy(ptr->lecture, buffer.lecture);
   strcpy(ptr->tutorial, buffer.tutorial);
   strcpy(ptr->practical, buffer.practical);
}
