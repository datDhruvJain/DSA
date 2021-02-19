#include<iostream>

/* 
   Stack class does stuff
   */
class Stack {

	int * stk;
	int size;
	int t = -1;

	public:
	Stack(int size = 5) {
		this -> size = size;
		stk = new int[size];
	}

	int getSize() {
		if (t != -1) return t;
		else return 0;
	}

	int isEmpty(){
		if (t < 0) return true;
		else return false;
	}

	int isFull() {
		if (t == size - 1) return true;
		else return false;
	}

	int top() {
		if (!isEmpty()) return stk[t];
		else return -1;
	}

	void push(int x) {
		if (!isFull()) {
			t++;
			stk[t] = x;
		}

		else {
			std::cout << ("Stack Overflow Error") << std::endl;
		}
	}

	int pop() {
		if (!isEmpty()) return stk[t--];
		else return -1;

	}
};

void reversePrinter(int arr[], int n) {
	Stack s(n);
	for (int i = 0; i < n; i++) {
		s.push(arr[i]);
	}

	//while (s.isEmpty() != true) {
	//    std::cout << s.pop() << " " << std::endl; 
	//}

	for(int i =0; i<n; i++){
		std::cout << s.pop() << " ";
	}
}

void test_1() {
	std::cout << "Test case 1" << std::endl;
	int arr[] = {10,15,95,40,24,17};
	reversePrinter(arr, sizeof(arr)/sizeof(int));
}

void test_2(){
	std::cout << "Test case 2" << std::endl;
	int arr[] = {15};
	reversePrinter(arr, sizeof(arr)/sizeof(int));
}

int main() {
	test_1();
	std::cout << std::endl;
	test_2();
}
