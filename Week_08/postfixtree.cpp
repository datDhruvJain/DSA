#include<iostream>

class Node{
	public:
	char data;
	Node* right = NULL;
	Node* left = NULL;
};

class Stack {

	int size;
	int t = -1;

	public:
	char * stk;
	Stack(int size = 5) {
		this -> size = size;
		stk = new char[size];
	}

	int getSize() {
		if (t != -1) return t;
		else return 0;
	}

	bool isEmpty(){
		if (t < 0) return true;
		else return false;
	}

	bool isFull() {
		if (t == size - 1) return true;
		else return false;
	}

	char top() {
		if (!isEmpty()) return stk[t];
		else return -1;
	}

	void push(char x) {
		if (!isFull()) {
			t++;
			stk[t] = x;
		}

		else {
			std::cout << ("Stack Overflow Error") << std::endl;
		}
	}

	char pop() {
		if (!isEmpty()) {
			int temp = stk[t];
			t--;
			return temp;
		}
		else return -1;

	}
};

class ExpressionTree{
	public:
	
	Stack s;
	Node* constructExpressionTree(Stack* s){
		if (s->isEmpty()){
			return NULL;
		}

		char x = s->pop();
		Node* t = new Node;
		t -> data = x;

		if (x == '+' || x == '-' || x == '/' || x == '*' || x == '^'){
			t -> right = constructExpressionTree(s);
			t -> left = constructExpressionTree(s);
		}

		return t;
	}

	void walk(Node* n){
		Node* temp = n;
		if (temp!=NULL){
			walk(temp->left);
			std::cout << temp -> data;
			walk(temp->right);
		}
	}
};

int main(){

	


	ExpressionTree a;
	a.s.push('a');
	a.s.push('b');
	a.s.push('c');
	a.s.push('*');
	a.s.push('+');
	Node* lol = a.constructExpressionTree(&a.s);

	a.walk(lol);

	//std::cout << (lol-> left) -> data;
	//std::cout << lol -> data;
	//std::cout << ((lol-> right) -> left) -> data;
	//std::cout << (lol -> right) -> data;
	//std::cout << ((lol-> right) -> right) -> data;
	

}
