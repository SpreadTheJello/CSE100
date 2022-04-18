#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

string HuffmanEncodings[0];

struct Node {
    Node* left; // basic left node for huffman tree
    Node* right; // basic right node for huffman tree
    string letter;
    int frequency;
    int unique_id;
    
    Node(string letter, int frequency){
        left = NULL; 
        right = NULL;
        this->letter = letter;
        this->frequency = frequency;
        this->unique_id = 0; // set to 0 (no problem)
    }
    
    Node(string letter, int frequency, int unique_id){
        left = NULL;
        right = NULL;
        this->letter = letter;
        this->frequency = frequency;
        this->unique_id = unique_id; // dont set to 0 if theres a unique id
    }
};

struct compare {
    bool operator() (Node* left, Node* right){ // returns true or false if there is a unique id
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
        if(minHeapRoot->letter.compare("!") != 0){ // sets each letter with their bytes
            for (int i = 0; i < size; i++){
                if(minHeapRoot->letter.compare(alphabet[i]) == 0){
                    HuffmanEncodings[i] = encondings;
                }
            }
        }
        if(minHeapRoot->letter.compare("!") == 0){ // if its a summation node (parent)
            print(minHeapRoot->left, encondings + "0", alphabet, size); // left traverse
            print(minHeapRoot->right, encondings + "1", alphabet, size); // right traverse
        }
    }
}

void Huffman(int size, string A[], vector<int>& C) {
    priority_queue<Node*, vector<Node*>, compare> HuffmanHeap; // prirority queue is a list that is sorted greatest to least values
    Node* root = NULL; // set our 3 nodes to NULL
    Node* left = NULL;
    Node* right = NULL;
    
    for (int i = 0; i < size; i++) {
        Node* temp = new Node(A[i], C[i], i + 1); // set array of node containing letter, freq, unique_id
        HuffmanHeap.push(temp);
    }

    while(HuffmanHeap.size() > 1) {
        left = HuffmanHeap.top(); // extracts the min
        HuffmanHeap.pop();
        right = HuffmanHeap.top(); // extracts the 2nd min
        HuffmanHeap.pop();
        
        Node* newParent = new Node("!", (left->frequency + right->frequency)); // create summation node
        root = newParent;
        if(left->frequency == right->frequency && left->unique_id > right->unique_id){ // swaps the child nodes if left is greater than right
            root->left = right;
            root->right = left;
            root->unique_id = right->unique_id;
        }
        else{
            root->left = left;
            root->right = right;
            root->unique_id = left->unique_id;
        }

        HuffmanHeap.push(root); // push in finalized summation root
    }
    print(HuffmanHeap.top(), "", A, size); 
    
    char j = 'A';
    for (int i = 0; j <= 'F'; i++, j++) { // prints the "letter:byte"
        cout << j << ":" << HuffmanEncodings[i] << endl;
    }
}


int main(int argc, char** argv) { 
    int size = 6;
    int value = 0;
    vector<int> C; // input vector
    string A[size]; // letters
    
    for (int i = 0; i < size; i++) {
        cin >> value;
        C.push_back(value); // adds input at end of C
        A[i] = "K" + to_string(i); // set what each letter's order is
    }
    
    Huffman(size, A, C);
    return 0;
}