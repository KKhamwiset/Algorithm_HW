#include <iostream>
#include <vector>
#include <climits>
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
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);

    int startVertex = 0;
    key[startVertex] = 0;
    
    for (int count = 0; count < n; count++) {
        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }
        
        if (u == -1) break;
        
        inMST[u] = true;
        
        for (int v = 0; v < n; v++) {
            if (graph[u][v] > 0 && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
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