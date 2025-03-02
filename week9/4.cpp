#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<vector<int>> &adj, int s, int e, int w = 1) {
    adj[s - 1][e - 1] = w;
}

int bfs(vector<vector<int>> &adj, int source, int maxRange) {
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> distance(n, -1);
    
    queue<int> q;
    q.push(source);
    visited[source] = true;
    distance[source] = 0;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (adj[current][i] != 0 && !visited[i]) {
                visited[i] = true;
                distance[i] = distance[current] + 1;
                q.push(i);
            }
        }
    }
    // for (auto i : distance) {
    //     cout << i << " ";
    // }
    cout << endl;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (distance[i] == -1 || distance[i] > maxRange) {
            count++;
        }
    }
    
    return count;
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
    
    int s, d;
    while (true) {
        cin >> s >> d;
        if (s == 0 && d == 0) {
            break;
        }
        addEdge(graph, s, d);
    }
    printGraph(graph);
    int startVertex, maxRange;
    cin >> startVertex >> maxRange;
    
    cout << bfs(graph, startVertex - 1, maxRange) << endl;
    
    return 0;
}