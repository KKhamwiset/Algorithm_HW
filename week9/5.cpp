#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int bfs(vector<vector<int>> &grid, int startRow, int startCol) {
    int n = grid.size();
    int m = grid[0].size();
    int directionX[] = {0,1,0,-1};
    int directionY[] = {1,0,-1,0};
    int targetColor = grid[startRow][startCol];
    int count = 0;
    queue<pair<int,int>> q;
    q.push({startRow,startCol});
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0 ; i < 4 ;i++){
            int nextX = x + directionX[i];
            int nextY = y + directionY[i];
            if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && grid[nextX][nextY] == targetColor){
                grid[nextX][nextY] = 0;
                q.push({nextX,nextY});
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
    cout << result << endl;
    
    return 0;
}