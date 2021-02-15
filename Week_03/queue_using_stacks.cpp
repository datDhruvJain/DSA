#include<iostream>


class stack {
	int *stk;
	int t = -1;

	public:
	stack(size) {
		stk = new int[size];
	}

	void push(int x) {
		if (!isEmpty()){
			stk[t];
		}
		else return -1;
	}
	
	int pop() {
		if (!isFull()) {
			// TODO : Check if decrement works or not
			return stk[t--];
		}
		else return -1;
	}
	

	int top(){
		if (!isEmpty()) {
			return stack[0];
		}
		else return -1;
	}

	bool isEmpty() {
		if (t == 0) {
			return true;
		}
		return false;
	}

	bool isFull() {
		if (t == sizeof(stack)/sizeof(stack[0])) {
		return true
		}

		else return false;
	}
};

class queue {
	stack s1(10);
	stack s2(10);
	public:
		void enQueue(int x) {
			s2.push(x);
		}

		int deQueue() {
			while (s1.isEmpty()==1){
				s1.push(s2.pop()) 
			}
		}
}
