#include <iostream>
using namespace std;

int left(int i){ // helper func
    return 2*i+1;
}

int right(int i){ // helper func
    return 2*i+2;
}

void maxHeapify(int arr[], int s, int i){
    int largest = i; // largest is the root
    int l = left(i); // gets left child of root
    int r = right(i); // gets right child of root

    if(l < s && arr[l] > arr[i]){ // if left child is larger than the root, we set left child as largest
        largest = l;
    }
    else{
        largest = i; // else largest will be root
    }
    if(r < s && arr[r] > arr[largest]){ // if right child is larger than the root, we set right child as largest
        largest = r;
    }
    if(largest != i){ // if largest and root are not equal, we swap A[i] with A[largest]
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, s, largest); // recursively call subtree
    }
}

void heapSort(int arr[], int s){
    for(int i = (s/2)-1; i >= 0; i--){
        maxHeapify(arr, s, i); // rearranges roots/childs
    }
    for(int i = s-1; i > 0; i--){ // after sorted, root is sent to end and finds the next largest by calling maxHeap again.
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        maxHeapify(arr, i, 0);
    }

}

int main(){
    int arr_size; // gets size of array from user
    cin >> arr_size;
    int arr [arr_size];

    for(int i = 0; i < arr_size; i++){ // gets array input from user
        cin >> arr[i];
    }

    heapSort(arr, arr_size);

    for(int i = 0; i < arr_size; i++){
        cout << arr[i] << ";";
    }
    return 0;
    
}