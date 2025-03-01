#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<vector<int>> &adj, int s, int e, int w) {
    adj[s - 1][e - 1] = w;
    adj[e - 1][s - 1] = w;
}

int bfs(vector<vector<int>> &adj, int source, int destination) {
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> distance(n, 0);
    
    queue<int> q;
    q.push(source);
    visited[source] = true;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        if (current == destination) {
            return distance[current];
        }
        
        for (int i = 0; i < n; i++) {
            if (adj[current][i] != 0 && !visited[i]) {
                visited[i] = true;
                distance[i] = distance[current] + 1;
                q.push(i);
            }
        }
    }
    
    return -1; 
}

void printGraph(vector<vector<int>> adj) {
    for (int i = 0; i < adj.size(); i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        int vertex;
        cin >> vertex;
        int edges = -1;
        while (edges != 0) {
            cin >> edges;
            if (edges != 0) {
                addEdge(graph, vertex, edges, 1);
            }
            else{
                break;
            }
        }
    }
    int source, destination;
    cin >> source >> destination;

    int shortestPath = bfs(graph, source - 1, destination - 1);
    cout << shortestPath << endl;
    
    return 0;
}