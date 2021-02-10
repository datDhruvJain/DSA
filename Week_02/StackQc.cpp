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
	int a,b;
	int temp;
	Stack s(n);

	for (int i=0; i<n;i++){
		if (!(arr[i]=='+' || arr[i] == '-' || arr[i] == '/'|| arr[i] == '*'|| arr[i] == '^')){
			s.push((int)(arr[i]-'0'));
		}

		else if (arr[i]=='+') {
			b = s.pop();
			a = s.pop();
			s.push(a+b);

		}

		else if (arr[i]=='-') {
			b = s.pop();
			a = s.pop();
			s.push(a-b);
		}

		else if (arr[i]=='/') {
			b = s.pop();
			a = s.pop();
			s.push(a/b);
		}

		else if (arr[i]=='*') {
			b = s.pop();
			a = s.pop();
			s.push(a * b);
		}

		else if (arr[i]=='^') {
			b = s.pop();
			a = s.pop();
			s.push(a ^ b);
		}
	}
	std::cout << s.pop() << std::endl;
	
}



int main(){
	postfixEvaluator();
}