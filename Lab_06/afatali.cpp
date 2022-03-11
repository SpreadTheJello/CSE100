#include <iostream>
#include <list>

using namespace std;

int m;

void hashInsert(list<int> T[], int k){
    int i = 0, j;
    while(i != m){
        j = k%m;
        T[j].push_front(k);
        i++;
    }
    if(i == m){
        cout << "hash table overflow";    
    }
}

int main(){
    cin >> m;
    list<int>T[m];
    char command;
    int k;

    while(m != 0){
        cin >> command;
        if(command == 'i'){
            cin >> k;
            hashInsert(T, k);
        }
        if(command == 'd'){
            cin >> k;
            //hashDelete(T, k);
        }
        if(command == 's'){
            cin >> k;
            //hashSearch(T, k);
        }
        if(command == 'o'){
            //hashPrint(T);
        }
        if(command == 'e'){
            break;
        }
    }
}