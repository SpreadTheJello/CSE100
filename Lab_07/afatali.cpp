#include <limits.h>
#include <iostream>

using namespace std;

void extendedBottomUpCutRod(int* p, int n){ // from textbook page 369
    int* r = new int[n+1];
    int* s = new int[n+1];
    r[0] = 0;
    int q = INT_MIN;
    
    for(int j = 1; j < n; j++){
        q = INT_MIN;
        for(int i = 1; i <= j; i++){
            if(q < p[i] + r[j-i]){
                q = p[i] + r[j-i];
                s[j] = i;
            }
        }
        r[j] = q;
    }  

    n = n - 1; // prints r and s values
    cout << r[n] << endl;
    while(n > 0){
        cout << s[n] << " ";
        n = n-s[n];
    }
    cout << "-1" << endl;
}

int main(){
    int n;
    cin >> n;
    
    int* p = new int[n + 1];
    p[0] = 0;

    for(int i = 1; i < n + 1; i++){
        cin >> p[i];
    }

    extendedBottomUpCutRod(p, n+1);

    return 0;
}
