#include <iostream>
using namespace std;

void sort(int a[], int s){
}

int main(){
    int arr_size; // gets size of array from user
    cin >> arr_size;
    int arr [arr_size];

    for(int i = 0; i < arr_size; i++){ // gets array input from user
        cin >> arr[i];
    }

    sort(arr, arr_size);

    return 0;
}