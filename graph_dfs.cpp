//PROBLEM STATEMENT:Calculate Water Footprints for different Agricultural Products
#include <iostream>
#include <string>
#define MAX 20
using namespace std;
class Graph {
private:
    struct Node {
        int vertex;
        string name;
		string brand;
		string place;
		int waterconsumption;
		string watersource;
        struct Node* next;
    }* G[MAX], *p, *temp;     
    bool visited[MAX]; 
    int vertices;

public:
    Graph(int v);                
    struct Node* createNode(int v);
    void addEdges(int edges[][2], int e); 
    void insert(int vs, int vd); 
    void DFS(int source);       
};

Graph::Node* Graph::createNode(int v) {
    temp = new Node;
    temp->vertex = v;
    temp->next = NULL;
    return temp;
}

Graph::Graph(int v) {
    p = NULL;
    temp = NULL;
    vertices = v;
    for (int i = 0; i < v; i++) {
        G[i] = NULL;
        visited[i] = false;
    }
}

void Graph::addEdges(int edges[][2], int e) {
    for (int i = 0; i < e; i++) {
        int vs = edges[i][0];
        int vd = edges[i][1];
        insert(vs, vd); 
    }
}

void Graph::insert(int vs, int vd) {
    temp = createNode(vd);
    if (G[vs] == NULL) {
        G[vs] = temp;
        return;
    }
        p = G[vs];
        while (p->next != NULL)
            p = p->next;
        p->next = temp;
}

void Graph::DFS(int source) {
    cout << source << " --> ";
    visited[source] = true;
    Node* p = G[source];
    while (p != NULL) {
        int vertex = p->vertex;
        if (!visited[vertex])
            DFS(vertex); 
        p = p->next;
    }
}

int main() {
    int vertices = 5;
    Graph graph(vertices);
   
    int edges[][2] = {
        {0, 1},
        {0, 2},
        {1, 3},
        {1, 4},
        {2, 4},
        {3, 4}
    };
    int numEdges = 6;
    
    graph.addEdges(edges, numEdges);
    int source = 0;
    cout << "\nDFS Traversal from vertex " << source << ":\n";
    graph.DFS(source);
    return 0;
}
