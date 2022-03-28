#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

void MatrixChainOrder(int p[], vector<vector<int> > &m, vector<vector<int> > &s, int n){
    for(int i = 1; i < n; i++){
        m[i][i] = 0;
    }
    for(int l = 2; l < n; l++){
        for(int i = 1; i < n - l + 1; i++){
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for(int k = i; k <= j-1; k++){
                int q = m[i][k] + m[k+1][j] + (p[i-1] * p[k] * p[j]);
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print(vector<vector<int> > s, int i, int j) {
    if (i == j) cout << "A" << (i - 1);
    else {
        cout << "(";
        print(s, i, s[i][j]);
        print(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main(){
    int n;
    cin >> n;
    int values[n];
    for(int i = 0; i <= n; i++){
        cin >> values[i];
    }
    vector<vector<int> > m;
    vector<vector<int> > s;
    m.resize(n+1, vector<int>(n+1,0));
    s.resize(n+1, vector<int>(n+1,0));

    MatrixChainOrder(values, m, s, n+1);
    cout << m[1][n] << "\n";
    print(s, 1, n);
    cout << "\n";
    return 0;
}