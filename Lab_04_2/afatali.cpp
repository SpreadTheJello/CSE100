#include <iostream>
using namespace std;

int partition(int arr[], int p, int r){
    int x = arr[r];
    int i = p - 1;
    for(int j = p; j <= r-1; j++){
        if(arr[j] <= x){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp;
    return i+1;
}

void quickSort(int arr[], int p, int r){
    if(p < r){
        int q = partition(arr, p, r);
        quickSort(arr, p, q-1);
        quickSort(arr, q+1, r);
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