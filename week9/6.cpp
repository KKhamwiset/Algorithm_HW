#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

vector<int> dijkstra(int start, int n, vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        int d = top.first;
        int u = top.second;
        pq.pop();

        if (d > dist[u]) continue;

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            int weight = graph[u][i].second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int v, e;
        cin >> v >> e;
        graph[v].push_back({e, 1});
        graph[e].push_back({v, 1});
    }

    int bestNode = -1, minMaxDist = INF;

    for (int i = 1; i <= N; i++) {
        vector<int> dist = dijkstra(i, N, graph);
        int maxDist = 0;

        for (int j = 1; j <= N; j++) {
            if (dist[j] != INF) {
                maxDist = max(maxDist, dist[j]);
            }
        }

        if (maxDist < minMaxDist) {
            minMaxDist = maxDist;
            bestNode = i;
        }
    }

    cout << bestNode << endl;
    return 0;
}