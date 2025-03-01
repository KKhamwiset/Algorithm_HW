#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int bfs(vector<vector<int>> &grid, int startRow, int startCol) {
    int n = grid.size();
    int m = grid[0].size();
    int targetColor = grid[startRow][startCol];
    int count = 1;    
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    queue<pair<int, int>> q;
    q.push({startCol, startRow});
    grid[startRow][startCol] = -1;
    
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nRow = x + dx[i];
            int nCol = y + dy[i];
            
            if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < m && grid[nRow][nCol] == targetColor) {
                grid[nRow][nCol] = 0;
                q.push({nCol, nRow});
                count++;
            }
        }
    }
    
    return count;
}

void printGrid(vector<vector<int>>& grid) {
    for (auto& row : grid) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> grid(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = (s[j] == 'W') ? 1 : 2;
        }
    }
    
    int x, y;
    cin >> x >> y;
    x--; y--;
    
    
    int result = bfs(grid, x, y);
    
    return 0;
}