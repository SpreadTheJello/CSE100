#include <iostream>
using namespace std;

void merge(int arr[], int p, int m, int s){
    int n = m - p + 1;
    int n2 = s - m;
    int arrL[n], arrR[n2];

    for(int i = 0; i < n; i++){
        arrL[i] = arr[p + i];
    }
    for(int j = 0; j < n2; j++){
        arrR[j] = arr[m + j + 1];
    }
    int i = 0, j = 0, k;
    // Textbook wanted these 2 lines (they dont work)
    // arrL[n+1] = INT_MAX;
    // arrR[n+1] = INT_MAX;

    for(k = p; i < n && j < n2; k++){
        if(arrL[i] < arrR[j]){
            arr[k] = arrL[i];
            i++;
        }
        else{
            arr[k] = arrR[j];
            j++;
        }
    }

    while(i<n){ // These 2 while loops where not in the textbook psuedo.
        arr[k] = arrL[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k] = arrR[j];
        k++;
        j++;
    }
}

void merge_sort(int arr[], int p, int s){
    if(p < s){
        int mid = (p + s)/2;
        merge_sort(arr, p, mid);
        merge_sort(arr, mid+1, s);
        merge(arr, p, mid, s);
    }
}

int main(){
    int arr_size; // gets size of array from user
    cin >> arr_size;
    int arr [arr_size];

    for(int i = 0; i < arr_size; i++){ // gets array input from user
        cin >> arr[i];
    }

    merge_sort(arr, 0, arr_size-1);

    for(int i = 0; i < arr_size; i++){
        cout << arr[i] << ";";
    }
    return 0;
}