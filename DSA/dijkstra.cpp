#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

void dijkstra(int start, vector<vector<pair<int,int>>> &graph, int n) {
    vector<int> dist(n, INF);
    dist[start] = 0;

    // Min-heap: {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (d > dist[node]) continue;  // skip outdated entry

        // explore neighbors
        for (auto &[next, weight] : graph[node]) {
            if (dist[node] + weight < dist[next]) {
                dist[next] = dist[node] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    // print results
    cout << "Shortest distances from " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": " << dist[i] << endl;
    }
}

int main() {
    int n = 5;  // number of nodes

    // adjacency list: graph[node] = { {neighbor, weight}, ... }
    vector<vector<pair<int,int>>> graph(n);

    // add edges
    auto add = [&](int u, int v, int w){
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // remove this if directed graph
    };

    add(0,1,2);
    add(0,3,1);
    add(1,2,3);
    add(1,3,2);
    add(2,4,1);
    add(3,4,3);

    dijkstra(0, graph, n);
}
