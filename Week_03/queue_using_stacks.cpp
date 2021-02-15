#include<iostream>

class Stack {
	
	int size;
	int t = -1;
	
	public:
	int *stk;

	Stack(int size=10){
		this -> size = size;
		stk = new int[size];
	}
	
	bool isEmpty(){
		if (t==-1) return true;
		else return false;
	}

	bool isFull(){
		if (t == (size-1)) return true;
		else return false;
	}

	void push(int x){
		if (!isFull()){
			// TODO: check increment operator
			t++;
			stk[t] = x;
		}
		else {
			std::cout << "Stack overflow error" << std::endl;
		}
	}

	int pop(){
		int temp;
		if (!isEmpty()){
			temp = stk[t];
			t--;
			return temp;
		}
		else return -1;
	}
};

class Queue{
	int size;
	Stack *s1;
	Stack *s2;
	public :
	Queue(int size){
		this -> size = size;
		s1 = new Stack(size);
		s2 = new Stack(size);
	}

	void enQueue(int x){
		if (!(*s2).isFull()){
			(*s2).push(x);
		}
	}

	void deQueue(){
		while(!(*s2).isEmpty()){
			(*s1).push((*s2).pop());

		}
		while(!(*s1).isEmpty()){
			std::cout << (*s1).pop() << std::endl;
		}
	}
};

int main(){
	Queue *q = new Queue(10);
	(*q).enQueue(5);
	(*q).enQueue(6);
	(*q).enQueue(7);
	(*q).enQueue(8);
	(*q).enQueue(9);
	(*q).deQueue();
	(*q).deQueue();
	(*q).deQueue();
	(*q).deQueue();
	(*q).deQueue();
	(*q).deQueue();
}