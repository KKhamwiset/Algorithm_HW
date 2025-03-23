#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;



const int INF = INT_MAX;
int dijkstraShortestPath(vector<pair<int, int>> adj[], int n, int src, int dest) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    vector<int> dist(n, INF);
    
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        int distance = pq.top().first;
        pq.pop();
        

        if (u == dest) {
            return distance;
        }
        
        if (distance > dist[u]) continue;
        
        for (auto edge : adj[u]) {
            int v = edge.first;    
            int weight = edge.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return -1;
}

int main() {
    int C;
    cin >> C; 
    
    while (C--) {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        
        vector<pair<int, int>> adj[n];
        
        for (int i = 0; i < m; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
        int result = dijkstraShortestPath(adj, n, s, t);
        cout << result << endl;
    }
    
    return 0;
}