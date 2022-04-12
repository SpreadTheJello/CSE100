#include <iostream>
#include <list>
#include <stack>

using namespace std;
// Watched a youtube tutorial and got help from g4g and stackoverflow forum

class Graph {
    int vertex2;
    list<int> *adjacent;
    void fillNode(int vertex, bool visited[], stack<int> &Stack);
    void DFS(int vertex, bool visited[],int node,int ar[]);

    public:
    Graph(int vertex2);
    void addSCC(int vertex, int w);
    void print(int node,int arr[]);
    Graph transpose();
};

Graph::Graph(int vertex2){
    this->vertex2 = vertex2;
    adjacent = new list<int>[vertex2];
}

void Graph::DFS(int vertex, bool visited[], int node, int arr[]){  
    visited[vertex] = true;
    arr[vertex] = node;
    for (list<int>::iterator i = adjacent[vertex].begin(); i != adjacent[vertex].end(); i++){
        if (visited[*i] == false){
            DFS(*i, visited, node, arr);
        }
    }
}

Graph Graph::transpose(){
    Graph g(vertex2);
    for (int vertex = 0; vertex < vertex2; vertex++){
        for(list<int>::iterator i = adjacent[vertex].begin(); i != adjacent[vertex].end(); i++){
            g.adjacent[*i].push_back(vertex);
        }
    }
    return g;
}

void Graph::addSCC(int vertex, int w){
    adjacent[vertex].push_back(w);
}

void Graph::fillNode(int vertex, bool visited[], stack<int> &Stack){
    visited[vertex] = true;
    for(list<int>::iterator i = adjacent[vertex].begin(); i != adjacent[vertex].end(); i++){
        if(visited[*i] == false){
            fillNode(*i, visited, Stack);
        }
    }
    Stack.push(vertex);
}

void Graph::print(int node,int arr[]){
    stack<int> Nodes;
    bool *visited = new bool[vertex2];

    for(int i = 0; i < vertex2; i++){
        visited[i] = false;
    }

    for(int i = 0; i < vertex2; i++){
        if(visited[i] == false){
            fillNode(i, visited, Nodes);
        }
    }
    Graph gr = transpose();

    for(int i = 0; i < vertex2; i++){
        visited[i] = false;
    }

    while (Nodes.empty() == false){
        int vertex = Nodes.top();
        Nodes.pop();
        if (visited[vertex] == false){
            gr.DFS(vertex, visited, vertex, arr);
            int min = vertex;
            for(int i = 0; i < node; i++){
                if(arr[i] == vertex){
                    if(min > i){
                        min = i;
                    }
                }
            }
            for(int i = 0; i < node; i++){
                if(arr[i] == vertex){
                    arr[i] = min;
                }
            }
        }
    }
}

int main(){
    int nodes;
    int edges;
    cin >> nodes;
    cin >> edges;
    Graph G(nodes);

    for(int i = 0; i < edges; i++){
        int u, w;
        cin >> u >> w;
        G.addSCC(u,w);
    }

    int arr[nodes];
    for(int i = 0; i < nodes; i++){
        arr[i] = nodes + 2;
    }
    G.print(nodes, arr);

    for(int i = 0; i < nodes; i++){
        cout << arr[i] << endl;
    }
    return 0;
}