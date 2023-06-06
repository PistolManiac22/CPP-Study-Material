#include <iostream>

using namespace std;

struct Edge {
    int src, dest, weight;
};

void printGraph(const Edge* graph, int E) {
    for (int i = 0; i < E; i++) {
        cout << graph[i].src << " -- " << graph[i].dest << " : " << graph[i].weight << endl;
    }
}

int find(int* parent, int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int* parent, int x, int y) {
    parent[x] = y;
}

Edge* KruskalMST(Edge* edges, int V, int E) {
    Edge* result = new Edge[V - 1]; 
    int* parent = new int[V]; 

    for (int i = 0; i < V; i++) {
        parent[i] = -1;
    }

    int edgeCount = 0;
    int index = 0;

    while (edgeCount < V - 1) {
        Edge nextEdge = edges[index++];

        int x = find(parent, nextEdge.src);
        int y = find(parent, nextEdge.dest);

        if (x != y) {
            result[edgeCount++] = nextEdge;
            Union(parent, x, y);
        }
    }

    delete[] parent;
    return result;
}

int main() {
    int V = 5;
    int E = 5;

    Edge* edges = new Edge[E];
    edges[0] = {0, 1, 2};
    edges[1] = {0, 2, 3};
    edges[2] = {1, 3, 1};
    edges[3] = {2, 3, 5};
    edges[4] = {2, 4, 4};

    Edge* MST = KruskalMST(edges, V, E);
    cout << "Minimum Spanning Tree:" << endl;
    printGraph(MST, V - 1);

    delete[] edges;
    delete[] MST;

    return 0;
}