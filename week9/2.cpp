#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<vector<int>> &adj, int s, int e, int w) {
    adj[s - 1][e - 1] = w;
}

bool solve(vector<vector<int>>& graph, int startVertex) {
    bool f = false;
    for (int i = 0; i < graph.size(); i++) {
        if (graph[startVertex][i] == 0 && i != startVertex){
            f = true;
            cout << i + 1 << " ";
        }
    }
    return f;
}
void printGraph(vector<vector<int>> adj) {
    for (int i = 0; i < adj.size(); i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
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