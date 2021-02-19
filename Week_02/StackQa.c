#include<stdio.h>
#include<stdlib.h>

int *stk;
int size;
int t = -1;

int getSize() {
	if (t != -1) return t;
	else return 0;
}

int isEmpty(){
	if (t < 0) return 1;
	else return 0;
}

int isFull() {
	if (t == size - 1) return 1;
	else return 0;
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
		printf("%s","Stack Overflow Error\n");
	}
}

int pop() {
	if (!isEmpty()) return stk[t--];
	else return -1;

}


void reversePrinter(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		push(arr[i]);
	}

	for(int i =0; i<n; i++){
	    printf(" %d",pop());
        
	}
}

void test_1() {
	printf("%s", "Test case 1");
	int arr[] = {10,15,95,40,24,17};
	stk = arr;
	size = sizeof(arr)/sizeof(int);
	reversePrinter(stk,size);
}

void test_2(){
	printf("%s", "Test case 2");
	int arr[] = {15};
	stk = arr;
	size = sizeof(arr)/sizeof(int);
	reversePrinter(stk,size);
}

int main() {
	test_1();
    printf("\n");
	test_2();
}
