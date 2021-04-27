
#include<stdio.h>
#include<stdlib.h>

// int merge_sort(){}

// --- Quick Sort begins ---

// Swap two elements in an array
int swap(int* a, int* b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

// Get the pivot element and arragnge the array
int place_pivot(int arr[], int low, int high){
    int ele = arr[low];
    int i = low+1;
    int j = high;
    int temp;

    while (j>=i){
        if (arr[i]<=ele) {i++;}
        if (arr[j]>=ele) {j--;}
        if (j>i && arr[i]>ele && arr[j]<ele){
            
            swap(&arr[i], &arr[j]);
            i++;j--;
        }
    }

    swap(&arr[j], &arr[low]);

    return j;
}

int quick_sort(int arr[], int begin, int end) {
    if (end>=begin){
        int pivot = place_pivot(arr, begin, end);
        quick_sort(arr, begin, pivot-1);
        quick_sort(arr, pivot+1, end);
    }
}

int main(){
    int arr[] = {9,8,7,6,5,4,3,2,1};
    //quick_sort(arr, 0, 8);
    for (int i=0; i<8;i++){
        printf("%d",arr[i]);
    }
}