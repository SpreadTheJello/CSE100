#include <iostream>

using namespace std;

int main(){
    int size = 0;
    int temp;
    int temparray;
    cin >> size;
    int array[size];
    for (int i = 0; i < size; i++){
        cin >> temp;
        array[i] = temp;
    }
    for (int i = 1; i < size; i++){
        for (int g = 0; g < i; g++){
            if (array[i] < array[g]){
                temparray = array[g];
                array[g] = array[i];
                array[i] = temparray;
            }
        }
        for(int k = 0; k <= i; k++){
            cout << array[k] << ";";
        }
        cout<<endl;
    }
    
    return 0;
}