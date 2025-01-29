#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void dijkstra(int n, vector<vector<int>> &graph, int source) {
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pq.push({dist[v], v});
            }
        }
    }

    // Printing shortest distances
    cout << "Node\tDistance from Source" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << "\t" << (dist[i] == INF ? -1 : dist[i]) << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    dijkstra(n, graph, source);

    return 0;
}
