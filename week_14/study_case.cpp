#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const int INF = 1000000;

class SocialNetwork {
private:
    int V;
    vector<vector<int>> adj;
    vector<string> names;

public:
    SocialNetwork(int vertices) {
        V = vertices;
        adj.resize(V);
        names.resize(V);
    }

    void setUserName(int id, string name) {
        names[id] = name;
    }

    void addFriendship(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << names[v] << " ";

        for (int u : adj[v]) {
            if (!visited[u]) {
                SocialNetwork::DFS(u, visited);
            }
        }
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << names[v] << " ";

            for (int u : adj[v]) {
                if (!visited[u]) {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
    }

    void dijkstra(int start) {
        vector<int> dist(V, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (int v : adj[u]) {
                int weight = 1; 
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Tingkat/Jarak pertemanan dari " << names[start] << ":" << endl;
        for (int i = 0; i < V; i++) {
            if (dist[i] == INF) {
                cout << "Ke " << names[i] << " : Tidak terhubung" << endl;
            } else {
                cout << "Ke " << names[i] << " : " << dist[i] << " langkah" << endl;
            }
        }
    }
};

int main() {
    SocialNetwork sn(5);

    sn.setUserName(0, "Andi");
    sn.setUserName(1, "Budi");
    sn.setUserName(2, "Citra");
    sn.setUserName(3, "Dina");
    sn.setUserName(4, "Eko");

    sn.addFriendship(0, 1);
    sn.addFriendship(0, 2);
    sn.addFriendship(1, 3);
    sn.addFriendship(2, 4);

    cout << "DFS (Menemukan semua teman terhubung):" << endl;
    vector<bool> visited(5, false);
    sn.SocialNetwork::DFS(0, visited);
    cout << "\n\n";

    cout << "BFS (Menelusuri per level jaringan):" << endl;
    sn.BFS(0);
    cout << "\n\n";

    cout << "Dijkstra (Jalur Hubungan Terpendek):" << endl;
    sn.dijkstra(0);

    return 0;
}