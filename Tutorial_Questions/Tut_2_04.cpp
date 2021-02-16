#include<iostream>

int *arr;
int size;

using namespace std;

void helper(){
	arr[0] = -1;
	arr[1] = 0;
	int i;
	while(i<size){
		if(i>0){
			cout << i << " ";
		}
		else {
			cout << i++ << " ";
		}
		i*=2;
	}
}

int main(){
	size = 100;
	arr = new int[size];
	for(int i=0; i<size; i++){
		arr[i] = -1;
	}

	helper();
}