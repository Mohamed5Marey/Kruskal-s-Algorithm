#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

class Graph {
    int V, E;
    vector<Edge> edges;
    vector<Edge> mst;

public:
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({ u, v, w });
    }

    void KruskalMST() {
        sort(edges.begin(), edges.end(), compareEdges);
        vector<int> parent(V), rank(V, 0);
        for (int v = 0; v < V; ++v)
            parent[v] = v;
        for (Edge& edge : edges) {
            int x = find(parent, edge.src);
            int y = find(parent, edge.dest);
            if (x != y) {
                mst.push_back(edge);
                unionSets(parent, rank, x, y);
            }
        }
        printMST();
    }

private:
    int find(vector<int>& parent, int i) {
        if (parent[i] != i)
            parent[i] = find(parent, parent[i]);
        return parent[i];
    }

    void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
        int xroot = find(parent, x);
        int yroot = find(parent, y);
        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }

    void printMST() {
        cout << "Edges in the MST:\n";
        for (Edge& edge : mst)
            cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
    }
};

int main() {
    int V = 4;
    int E = 5;
    Graph g(V, E);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.KruskalMST();
    return 0;
}
