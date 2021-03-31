#include<iostream>

class mergesort{

		static void merge(int arr[], int l, int m, int r){
			
			// Define sizes of temporary arrays.
			int size1 = m - l + 1;
			int size2 = r -m;
			// And create new arrays.
			int L[size1], R[size2];

            // copy values into arrays
			int lcpy = l;
            int mcpy = m;
            
            for(int i=0;i<size1;i++){
				L[i] = arr[lcpy];
				lcpy++;
			}

            for (int i=0;i<size2;i++){
                R[i] = arr[mcpy];
                mcpy++;
            }

            int i,j = 0;
            while(i<size1 && j<size2){
                if (L[i] < R[j]){
                    arr[l] = L[i];
                    i++;
                }
                else {
                    arr[l] = R[j];
                    j++;
                }
                l++;
            }

            while(i<size1){
                arr[l] = L[i];
                i++;
                l++;
            }

            while(j<size2){
                arr[l] = L[j];
                j++;
                l++;
            }
		}

        public:
        void static sort(int arr[], int l, int r){
            if(l>=r){
                return;
            }

            int m = l + (r-l)/2;
            sort(arr,l,m);
            sort(arr,m+1,r);
            merge(arr, l, m, r);
        }
};

int main(){
    int arr[] = {4,3,2,1};
    mergesort::sort(arr,0,3);
    for(int i=0;i<9;i++){
    std::cout << arr[i]<< "";
    }
}
