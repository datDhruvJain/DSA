#include<iostream>

int *arr;
int size;

using namespace std;

void helper(){
	arr[0] = -1;
	arr[1] = 1;
	int i=0;
	while(i<size){
		if(arr[i]>0){
			cout << arr[i] << " : index is " << i << endl;

		}
		else if(arr[++i] > 0){
			cout << arr[i] << " : index is " << i << endl;
		}
		i*=2;
	}
}

int main(){
	size = 11;
	arr = new int[size];

	for(int i=0; i<size; i++){
		arr[i] = -1;
	}

	arr[2] = 1;
	arr[4] = 1;
	arr[8] = 1;

	helper();
}