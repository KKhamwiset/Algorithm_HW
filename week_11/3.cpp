#include <bits/stdc++.h>
using namespace std;
int findmaxSugar(vector<vector<int>>& sugar, int i, int j, int N, int M, vector<vector<int>>& memo) {
    if (i >= N || j >= M) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    memo[i][j] = max(findmaxSugar(sugar, i + 1, j, N, M, memo), findmaxSugar(sugar, i, j + 1, N, M, memo)) + sugar[i][j];
    
    return memo[i][j];
}
int main() {
    int N, M;
    cin >> N >> M;
    
   
    vector<vector<int>> sugar(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> sugar[i][j];
        }
    }
    
  
    vector<vector<int>> memo(N, vector<int>(M, -1));
    
   
    int result = findmaxSugar(sugar, 0, 0, N, M, memo);
    
    cout << result << endl;
    
    return 0;
}