#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

string HuffmanEncodings[0];

struct Node {
    Node* left;
    Node* right;
    string letter;
    int frequency;
    int unique_id;
    
    Node(string letter, int frequency){
        left = NULL;
        right = NULL;
        this->letter = letter;
        this->frequency = frequency;
        this->unique_id = 0;
    }
    
    Node(string letter, int frequency, int unique_id){
        left = NULL;
        right = NULL;
        this->letter = letter;
        this->frequency = frequency;
        this->unique_id = unique_id;
    }
};

struct compare {
    bool operator() (Node* left, Node* right){
        if(left->frequency == right->frequency){
            return (left->unique_id > right->unique_id);
        }
        else{
            return (left->frequency > right->frequency);
        }
    }
};


void print(Node* minHeapRoot, string encondings, string alphabet[], int size){
    if(minHeapRoot == NULL){
        return;
    }
    else{
        if(minHeapRoot->letter.compare("$") != 0){ 
            for (int i = 0; i < size; i++){
                if(minHeapRoot->letter.compare(alphabet[i]) == 0){
                    HuffmanEncodings[i] = encondings;
                }
            }
        }
        if(minHeapRoot->letter.compare("$") == 0){
            print(minHeapRoot->left, encondings + "0", alphabet, size);
            print(minHeapRoot->right, encondings + "1", alphabet, size);
        }
    }
}

void Huffman(int size, string A[], vector<int>& C) {
    priority_queue<Node*, vector<Node*>, compare> HuffmanHeap;
    Node* root = NULL;
    Node* left = NULL;
    Node* right = NULL;
    
    for (int i = 0; i < size; i++) {
        Node* temp = new Node(A[i], C[i], i + 1);
        HuffmanHeap.push(temp);
    }
    
    while(HuffmanHeap.size() > 1) {
        left = HuffmanHeap.top(); //extracts the min
        HuffmanHeap.pop();
        right = HuffmanHeap.top();
        HuffmanHeap.pop();
        
        Node* newParent = new Node("$", (left->frequency + right->frequency));
        root = newParent;
        if(left->frequency == right->frequency && left->unique_id > right->unique_id){
            root->left = right;
            root->right = left;
            root->unique_id = right->unique_id;
        }
        else{
            root->left = left;
            root->right = right;
            root->unique_id = left->unique_id;
        }

        HuffmanHeap.push(root);
    }
    print(HuffmanHeap.top(), "", A, size);
    
    char j = 'A';
    for (int i = 0; j <= 'F'; i++, j++) {
        cout << j << ":" << HuffmanEncodings[i] << endl;
    }
}


int main(int argc, char** argv) { 
    int size = 6;
    int value = 0;
    vector<int> C;
    string A[size];
    
    for (int i = 0; i < size; i++) {
        cin >> value;
        C.push_back(value);
        A[i] = "K" + to_string(i);
    }
    
    Huffman(size, A, C);
    return 0;
}