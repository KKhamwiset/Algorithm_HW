#include <bits/stdc++.h>
using namespace std;

bool dfs(int curr, int prev, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[curr] = true;
    
    for (auto neighbor : adj[curr]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, curr, adj, visited)) {
                return true;
            }
        }
        else if (neighbor != prev) {
            return true;
        }
    }
    return false;
}

bool checkCycle(vector<vector<int>>& adj, int n) {
    vector<bool> visited(n + 1, false);
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && !adj[i].empty()) {
            if (dfs(i, -1, adj, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        
        int e = -1;
        while (true) {
            cin >> e;
            if (e == 0) {
                break;
            }
            adj[v].push_back(e);
        }
    }
    
    cout << checkCycle(adj, n);
    
    return 0;
}