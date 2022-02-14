#include <iostream>
using namespace std;

int left(int i){
    return 2*i+1;
}

int right(int i){
    return 2*i+2;
}

void maxHeapify(int arr[], int s, int i){
    int largest = i;
    int l = left(i);
    int r = right(i);

    if(l < s && arr[l] > arr[i]){
        largest = l;
    }
    else{
        largest = i;
    }
    if(r < s && arr[r] > arr[largest]){
        largest = r;
    }
    if(largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, s, largest);
    }
}

void heapSort(int arr[], int s){
    for(int i = (s/2)-1; i >= 0; i--){
        maxHeapify(arr, s, i);
    }
    for(int i = s-1; i > 0; i--){
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