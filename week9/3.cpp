#include <iostream>
#include <vector>

using namespace std;

bool hasCycle(int v, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& inStack) {
    visited[v] = true;
    inStack[v] = true;
    
    for (int u : adj[v]) {
        if (!visited[u] && hasCycle(u, adj, visited, inStack))
            return true;
        else if (inStack[u])
            return true;
    }
    inStack[v] = false;
    return false;
}


bool cycle(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    vector<bool> inStack(n, false);
    

    for (int i = 0; i < n; i++) {
        if (!visited[i] && hasCycle(i, adj, visited, inStack))
            return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n; 
    vector<vector<int>> adj(n);
    
    for (int i = 0; i < n; i++) {
        int vertex, neighbor;
        cin >> vertex; 
        
        while (true) {
            cin >> neighbor;
            if (neighbor == 0){
                break;
            }
            adj[vertex - 1].push_back(neighbor - 1); 
        }
    }
    
    if (cycle(n, adj))
        cout << "1" << endl;
    else
        cout << "0" << endl; 
    
    return 0;
}