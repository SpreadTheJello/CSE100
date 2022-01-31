#include <iostream>
using namespace std;

void sort(int a[], int s){ // insertion sort function
    for(int i = 1; i < s; i++){
        int compare = a[i];
        int j;

        for(j = i - 1; j >= 0 && a[j] > compare; j = j - 1){
            a[j+1] = a[j];
        }
        a[j+1] = compare;

        for(int k = 0; k < i+1; k++){ // print as we go through loop
            cout << a[k] << ";";
        }
        cout << endl;
    }
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