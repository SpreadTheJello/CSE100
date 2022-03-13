#include <iostream>
#include <list>

using namespace std;

int m;

int h(int k){ // hash function
    return (k % m);
}

void hashInsert(list<int> T[], int k){ // hash insert
    int i = 0, j = h(k);
    if(m != 0){
        T[j].push_front(k);
    }
}

void hashPrint(list<int> T[]){ 
    list<int> :: iterator iter; // from https://en.cppreference.com/w/cpp/container/list
    for(int i = 0; i < m; i++){ // (used this in CSE30 with hash function before)
        cout << i << ":"; // prints the "0: 1: 2:, etc."
        for(iter = T[i].begin(); iter != T[i].end(); ++iter){ // print whats in that has according to the 0, 1, 2, etc.
            cout << *iter << "->";
        }
        cout << ";" << endl;
    }
}

void hashSearch(list<int> T[], int k){ 
    list<int> :: iterator iter; // also learned from https://en.cppreference.com/w/cpp/container/list
    bool found = false;
    int j = h(k), i = 0;
    for(iter = T[j].begin(); iter != T[j].end(); ++iter, i++){
        if(*iter == k){
            cout << k << ":FOUND_AT" << j << "," << i << ";" << endl;
            found = true;
        }
    }
    if(!found){
        cout << k << ":NOT_FOUND;" << endl;
    }
}

void hashDelete(list<int> T[], int k){
    list<int> :: iterator iter; // same concept as before
    bool removed = false;
    int j = h(k), i = 0;
    for(iter = T[j].begin(); iter != T[j].end(); ++iter, i++){
        if(*iter == k){
            T[i].erase(iter);
            cout << k << ":DELETED;" << endl;
            removed = true;
            break;
        }
    }
    if(!removed){
        cout << k << ":DELETE_FAILED;" << endl;
    }
}

int main(int argc, const char* argv[]){
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
            hashDelete(T, k);
        }
        if(command == 's'){
            cin >> k;
            hashSearch(T, k);
        }
        if(command == 'o'){
            hashPrint(T);
        }
        if(command == 'e'){
            break;
        }
    }
    return 0;
}