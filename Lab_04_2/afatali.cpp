#include <iostream>
using namespace std;

int partition(int arr[], int p, int r){ // this is the pivot function that will rearrange the subarray in place
    int x = arr[r]; // pivots end of array
    int i = p - 1; // index of smaller elem
    for(int j = p; j <= r-1; j++){
        if(arr[j] <= x){ // if the current element is smaller than the pivot we increment the index of smaller element
            i++;
            int temp = arr[i]; // swap smaller element with current element
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1]; // swap right of smaller element index and the right of it
    arr[i+1] = arr[r];
    arr[r] = temp;
    return i+1;
}

void quickSort(int arr[], int p, int r){ 
    if(p < r){ // once p isnt < r, recursive stops
        int q = partition(arr, p, r); // index of partition
        quickSort(arr, p, q-1); // recursivly sorts bottom half
        quickSort(arr, q+1, r); // recursivly sorts upper half
    }
}

int main(){
    int arr_size; // gets size of array from user
    cin >> arr_size;
    int arr [arr_size];

    for(int i = 0; i < arr_size; i++){ // gets array input from user
        cin >> arr[i];
    }

    quickSort(arr, 0, arr_size-1);

    for(int i = 0; i < arr_size; i++){
        cout << arr[i] << ";";
    }
    return 0;
    
}