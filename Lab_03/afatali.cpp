#include <iostream>
#include <limits.h>
using namespace std;

int maxCrossingSubArray(int arr[], int low, int mid, int high){
    int max_left, max_right;
    int left_sum = INT_MIN;
    int sum = 0;

    for(int i = mid; i >= low; i--){ // finds max subarray of left half
        sum = sum + arr[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }
    
    int right_sum = INT_MIN;
    sum = 0;
    for(int j = mid+1; j <= high; j++){ // finds max subarray of right half
        sum = sum + arr[j];
        if(sum > right_sum){
            right_sum = sum;
            max_right = j;
        }
    }
    return(max_left, max_right, left_sum + right_sum);
}

int maxSubArray(int arr[], int low, int high){
    int mid, left_low, left_high, left_sum, right_low, right_high, right_sum, cross_low, cross_high, cross_sum;

    if(high == low){ // base case
        return (low, high, arr[low]);
    }
    else{
        mid = (low+high)/2; // divide and conquer

        (left_low, left_high, left_sum) = maxSubArray(arr, low, mid); // finding maximum subarrays within the left
        (right_low, right_high, right_sum) = maxSubArray(arr, mid+1, high); // finding maximum subarrays within the right
        (cross_low, cross_high, cross_sum) = maxCrossingSubArray(arr, low, mid, high); //finding maximum subarray that crosses the midpoint

        if(left_sum >= right_sum && left_sum >= cross_sum){
            return (left_low, left_high, left_sum);
        }
        else if(right_sum >= left_sum && right_sum >= cross_sum){
            return(right_low, right_high, right_sum);
        }
        else{
            return (cross_low, cross_high, cross_sum);
        }
    }
}

int main(){
    int arr_size; // gets size of array from user
    cin >> arr_size;
    int arr [arr_size];

    for(int i = 0; i < arr_size; i++){ // gets array input from user
        cin >> arr[i];
    }

    int max_sum = maxSubArray(arr, 0, arr_size - 1);
    cout << max_sum;
    return 0;
    
}
