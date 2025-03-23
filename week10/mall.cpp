#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <string>
using namespace std;


pair<int, int> min_distance_node(vector<vector<int>>& dist, vector<vector<bool>>& visited, int n, int m) {
    int min_dist = INT_MAX;
    pair<int, int> min_node = {-1, -1};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && dist[i][j] < min_dist) {
                min_dist = dist[i][j];
                min_node = {i, j};
            }
        }
    }
    
    return min_node;
}

void solve(vector<string> grid, pair<int,int> start, pair<int,int> end) {
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};   
    int n = grid.size();
    int m = grid[0].size();
    

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    dist[start.first][start.second] = 0;

    while (true) {
        pair<int, int> r = min_distance_node(dist, visited, n, m);
        int row = r.first;
        int col = r.second;
        if (row == -1 || (row == end.first && col == end.second)) break;
        visited[row][col] = true;
        for (int i = 0; i < 4; i++) {
            int nr = row + dx[i];
            int nc = col + dy[i];
            
            if (nr < 0 || nr >= n || nc < 0 || nc >= m || 
                visited[nr][nc] || grid[nr][nc] == 'X') {
                continue;
            }
            int cost = 0; 
            if (isdigit(grid[nr][nc])) {
                cost = stoi(string(1, grid[nr][nc]));
            }
            
            if (dist[nr][nc] > dist[row][col] + cost) {
                dist[nr][nc] = dist[row][col] + cost;
            }
        }
    }
    
    cout << dist[end.first][end.second] << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    pair<int,int> start, end;
    
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') {
                start = {i, j};
            } else if (grid[i][j] == 'D') {
                end = {i, j};
            }
        }
    }
    
    solve(grid, start, end);
    return 0;
}