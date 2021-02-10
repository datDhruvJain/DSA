#include<iostream>

/* 
   Stack class does stuff
   */
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

int inputHelper(char arr[],int n){
	
	std::cout << "Enter the characters: " << std::endl;
	for (int i=0;i<n;i++) {
		std::cin >> arr[i];
	}
	return n;
}

void postfixEvaluator() {
	
	int n;
	std::cout << "Enter the size of the array: " << std::endl;
	std::cin >> n;
	char arr[n];
	inputHelper(arr,n);
	char a,b;
	int temp;
	Stack s(n);

	for (int i=0; i<n;i++){
		if (!(arr[i]=='+' || arr[i] == '-'|| arr[i] == '/'|| arr[i] == '*'|| arr[i] == '^')){
			s.push(arr[i]);
		}

		else if (arr[i]=='+') {
			b = s.pop();
			a = s.pop();
			s.push((int)a + (int)b);
		}

		else if (arr[i]=='-') {
			b = s.pop();
			a = s.pop();
			s.push((int)a + (int)b);
		}

		else if (arr[i]=='/') {
			b = s.pop();
			a = s.pop();
			s.push((int)a + (int)b);
		}

		else if (arr[i]=='*') {
			b = s.pop();
			a = s.pop();
			s.push((int)a + (int)b);
		}

		else if (arr[i]=='^') {
			b = s.pop();
			a = s.pop();
			s.push((int)a + (int)b);
		}
	}
	std::cout << (int) s.pop() << std::endl;
	
}



int main(){
	postfixEvaluator();
}