//PROBLEM STATEMENT:Calculate Water Footprints for different Agricultural Products
#include <iostream>
using namespace std;
#define MAX 20

class QueueLinked {
private:
    struct node {
        string name;
		string brand;
		string place;
		int waterconsumption;
		string watersource;
        struct node* next;
    } * front, * rear, * p, * temp;

public:
    QueueLinked() {
        front = NULL;
        rear = NULL;
        p = NULL;
        temp = NULL;
    }

    void ENQUEUE(int);
    int DEQUEUE();
    bool isEmpty();
};
void QueueLinked::ENQUEUE(string n, string br,string pl,int wc,string ws){
    temp=new struct node;
    temp->name=n;
    temp->brand=b;
    temp->place=pl;
    temp->waterconsumption=wc;
    temp->watersource=ws;
    temp->next=NULL;
    if(front==NULL){
        front=rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
}
int QueueLinked::DEQUEUE(){
    if(front==NULL){
        cout<<"\nSorry Queue is empty; can't print";
        return -1;
    }
    string n=front->name;
    string br=front->brand;
    string pl=front->place;
    int wc=front->waterconsumption;
    string ws=front->watersource;
    front=front->next;
    return x;
}
bool QueueLinked:: isEmpty() {
        return front == NULL;
    }

class Graph {
private:
    struct Node {
        int vertex;
        struct Node* next;
    }* G[MAX], * p, * temp;       
    bool visited[MAX]; 
    int vertices;

public:
    Graph(int v);
    struct Node* createNode(int v);
    void addEdges(int edges[][2], int e); ut
    void insert(int vs, int vd); 
    void BFS(int source);        
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
void Graph::BFS(int source) {
    QueueLinked q;
    q.ENQUEUE(source);
    visited[source] = true;

    while (!q.isEmpty()) {
        int current = q.DEQUEUE();
        if (current == -1) break; 
        cout << current << " --> ";
        Node* p = G[current];
        while (p != NULL) {
            int vertex = p->vertex;
            if (!visited[vertex]) {
                q.ENQUEUE(vertex);
                visited[vertex] = true;
            }
            p = p->next;
        }
    }
}

int main() {
    int vertices,x;
    cout<<"enter thenumber of vertices:";
    cin>>vertices;
    Graph graph(vertices);
    int edges[][5];
    
    int numEdges = 6;
    graph.addEdges(edges, numEdges);
    int source = 0;
    cout << "\nBFS Traversal from vertex " << source << ":\n";
    graph.BFS(source);
    return 0;
}
