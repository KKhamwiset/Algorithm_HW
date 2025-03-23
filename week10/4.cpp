#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n, vector<int>(n, 0));
    
    for (int i = 0; i < m; i++) {
        int s, d, l;
        cin >> s >> d >> l;
        
        graph[s][d] = l;
        graph[d][s] = l;
    }
    
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    int startVertex = 0;
    
    pq.push({0, startVertex});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        
        if (inMST[u]) {
            continue;
        }
        
        inMST[u] = true;
        
        for (int v = 0; v < n; v++) {
            if (graph[u][v] > 0 && !inMST[v]) {
                int edgeWeight = graph[u][v];
                pq.push({edgeWeight, v});
                if (!inMST[v] && (parent[v] == -1 || edgeWeight < graph[v][parent[v]])) {
                    parent[v] = u;
                }
            }
        }
    }
    
    int totalFlags = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            int pathLength = graph[i][parent[i]];
            totalFlags += (pathLength - 1);
        }
    }
    
    cout << totalFlags << endl;
    
    return 0;
}