#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adj; 

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    void display() {
        for(int i = 0; i < V; i++) {
            cout << "Vertex " << i << " : ";
            for(auto edge : adj[i]) {
                cout << "(" << edge.first << "," << edge.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4); 

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 3, 1);

    g.display(); 

    return 0;
}