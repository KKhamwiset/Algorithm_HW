#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<vector<int>> &adj, int s, int e, int w) {
    adj[s - 1][e - 1] = w;
}

vector<bool> findReachable(vector<vector<int>>& graph, int startVertex) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    
    q.push(startVertex);
    visited[startVertex] = true;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        for (int i = 0; i < n; i++) {
            if (graph[current][i] > 0 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    
    return visited;
}

bool solve(vector<vector<int>>& graph, int startVertex) {
    vector<bool> reachable = findReachable(graph, startVertex);
    bool found = false;
    for (int i = 0; i < graph.size(); i++) {
        if (!reachable[i] && i != startVertex) {
            found = true;
            cout << i + 1 << " "; 
        }
    }
    
    return found;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; i++) {
        int vertex;
        cin >> vertex;
        int edges = -1;
        while (true) {
            cin >> edges;
            if (edges == 0) break;
            addEdge(graph, vertex, edges, 1);
        }
    }
    
    int s;
    cin >> s;
    for (int i = 0; i < s; i++) {
        int startVertex;
        cin >> startVertex;
        
        if (!solve(graph, startVertex - 1)){
            cout << "0";    
        }
        cout << endl;
    }
    return 0;
}