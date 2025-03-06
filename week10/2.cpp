#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void addEdge(vector<vector<pair<int, int>>>& graph, int src, int dest, int weight) {
    int max_vertex = max(src - 1, dest - 1);
    if (max_vertex >= graph.size()) {
        graph.resize(max_vertex + 1);
    }
    
    graph[src - 1].push_back({dest - 1, weight});
}

int minDistance(vector<int> &dist,vector<bool> &visited){
    int min_ = INT_MAX,min_inx = -1;
    for (int i = 0 ; i < dist.size();i++){
        if (!visited[i] && dist[i] < min_){
            min_ = dist[i];
            min_inx = i;
        }
    }
    return min_inx;
}

pair<int,int> dijkstra(vector<vector<pair<int, int>>>& graph, int source) {
    vector<int> dist(graph.size(), INT_MAX);
    vector<bool> visited(graph.size(), false);
    dist[source] = 0;
    
    for (int count = 0; count < graph.size() - 1; count++) {
        int u = minDistance(dist, visited);
        if (u == -1){
            break;
          } 
        
        visited[u] = true;
        
        for (auto neighbor : graph[u]) {
            int v = neighbor.first;    
            int weight = neighbor.second;  
            if (!visited[v] && dist[u] != INT_MAX && 
                dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    int sum_dist = 0;
    int reachable = 0;
    for (int dist_ : dist){
        if (dist_ != INT_MAX && dist_ != 0){
            sum_dist += dist_;
            reachable++;
        }
    }
    return {sum_dist,reachable};
}

void printGraph(const vector<vector<pair<int, int>>>& graph) {
    cout << "Graph structure:" << endl;
    for (int i = 0; i < graph.size(); i++) {
        cout << "Vertex " << i + 1 << " is connected to: ";
        if (graph[i].empty()) {
            cout << "No outgoing edges";
        } else {
            for (const auto& neighbor : graph[i]) {
                cout << "(" << neighbor.first + 1 << ", weight: " << neighbor.second + 1 << ") ";
            }
        }
        cout << endl;
    }
    cout << "------------------------" << endl;
}
int main(){
    vector<vector<pair<int, int>>> graph;
    vector<int> insertedVertex;
    while (1){
        int start,end;
        cin >> start >> end;
        if (start == 0 && end == 0){
            break;
        }
        else{
            addEdge(graph,start,end,1);
        }
    }
    int result = 0;
    int totalDist = 0;
    for (int i = 0 ; i < graph.size();i++){
        int startvertex = i;
        pair<int,int> outcome = dijkstra(graph,startvertex);
        result += outcome.first;
        totalDist += outcome.second;
    }
    // printGraph(graph);
    // cout << "Result dist : " << totalDist << endl;
    double average = static_cast<double>(result) / totalDist;
    cout << fixed;
    cout.precision(3);
    cout << average << endl;
    return 0;
}
