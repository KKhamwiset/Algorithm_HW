#include <bits/stdc++.h>

using namespace std;


void addEdge(vector<vector<int>>& graph, int u, int v){
    graph[u - 1][v -1] = 1;
    graph[v - 1][u - 1] = 1;
}

int solve(vector<vector<int>>& graph) {
    int n = graph.size();
    int best = -1;
    int minMaxDistance = INT_MAX;
    
    for (int startNode = 0; startNode < n; startNode++) {
        vector<int> distances(n, INT_MAX);
        queue<int> q;
        
        distances[startNode] = 0;
        q.push(startNode);
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            for (int neighbor = 0; neighbor < n; neighbor++) {
                if (graph[current][neighbor] == 1 && distances[neighbor] == INT_MAX) {
                    distances[neighbor] = distances[current] + 1;
                    q.push(neighbor);
                }
            }
        }
        int maxDistance = 0;
        bool canReachAll = true;
        
        for (int i = 0; i < n; i++) {
            if (distances[i] == INT_MAX) {
                canReachAll = false;
                break;
            }
            maxDistance = max(maxDistance, distances[i]);
        }
        

        if (canReachAll && maxDistance < minMaxDistance) {
            minMaxDistance = maxDistance;
            best = startNode + 1; 
        }
    }
    
    return best;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(graph, u, v);
    }
    
    int result = solve(graph);
    cout << result << endl;
    
    return 0;
}