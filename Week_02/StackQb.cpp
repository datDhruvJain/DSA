#include<iostream>

/* 
   Stack class does stuff
*/
class Stack {

	char * stk;
	int size;
	int t = -1;

	public:
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

void checkBalance(char arr[], int n) {
	Stack s(n);
	for (int i = 0; i < n; i++) {
		if (arr[i] == '[') {
			s.push(arr[i]);
		}

		else if (arr[i] == ']') { 
			char ck = s.pop();
			if (ck != '[') {
				std::cout << "Unbalanced 1" << std::endl;
				break;
			}
		}
	}

	if (!s.isEmpty()) {
		s.pop();
		std::cout << s.top() <<"Unbalanced 2" << std::endl;
	}
}

int main() {
	char arr[] = {'a','+','c', '-', 'd', ']', 'k'};
	//char arr[] = {'a','+','[','c', '-', 'd', ']'};
	//char arr[] = {'a','+','[','c', '-', 'd', ']'};
	checkBalance(arr, sizeof(arr));
}
