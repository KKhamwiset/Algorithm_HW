#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void addEdge(vector<vector<int>>& graph,int s,int d,int w=1){
    graph[s - 1][d - 1]=w;
    graph[d - 1][s - 1]=w;
}
int PrimAlgorithm(vector<vector<int>>& graph,int start){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;
    vector<bool> visited (graph.size(),false);
    int result = 0;
    minheap.push({0,start - 1});
    while (!minheap.empty()){
        pair<int,int> ve = minheap.top();
        minheap.pop();
        int weight = ve.first;
        int c_vertex = ve.second;
        if (visited[c_vertex]){
            continue;
        }
        result += weight;
        visited[c_vertex] = true;
        for (int i = 0 ; i < graph[c_vertex].size();i++){
            if (!visited[i] && graph[c_vertex][i] > 0){
                minheap.push({graph[c_vertex][i], i});
            }
        }
    }
    return result;
}

int main() {
    int v,m;
    cin >> v >> m;
    vector<vector<int>>graph (v,vector<int>(v,0));
    for(int i=0;i < m ;i++){
        int source,dest,weight;
        cin >> source >> dest >> weight;
        addEdge(graph,source,dest,weight);
    }
    int startVertex;
    cin >> startVertex;
    int result = PrimAlgorithm(graph,startVertex);
    cout << result << endl;
    return 0;
}
