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
    
    void deleteNode(int index){
        Node* temp = head;
        if (index == count -1){
            for(int i=0;i<count-2;i++){
                temp = temp -> next;
            }
            free(temp->next);
            temp -> next = NULL;
            return;
        }

        for(int i=0; i<index-1; i++){
            temp = temp -> next;
        }

        temp -> next = (temp -> next) -> next;
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


// --- main function to test ---

int main(){
}