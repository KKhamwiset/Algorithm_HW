#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int Floyd(int n, vector<vector<int>>& capacity, int src, int dest, int tourists) {
    vector<vector<int>> minTrips(n, vector<int>(n, INT_MAX));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (capacity[i][j] > 0) {
                minTrips[i][j] = ceil((double)(tourists) / capacity[i][j]) + 1;
            }
            if (i == j) {
                minTrips[i][j] = 0;
            }
        }
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (minTrips[i][k] != INT_MAX && minTrips[k][j] != INT_MAX) {
                    minTrips[i][j] = min(minTrips[i][j], max(minTrips[i][k] , minTrips[k][j]));
                }
            }
        }
    }
    
    return (minTrips[src][dest] == INT_MAX) ? -1 : minTrips[src][dest];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> capacity(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int s, t, l;
        cin >> s >> t >> l;
        
        s--; 
        t--;
        
        capacity[s][t] = l;
        capacity[t][s] = l;
    }
    
    int src, dest, tourists;
    cin >> src >> dest >> tourists;
    
    src--; 
    dest--;
    
    int result = Floyd(n, capacity, src, dest, tourists);
    
    cout << result << endl;
    
    return 0;
}