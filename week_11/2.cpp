#include<bits/stdc++.h>
using namespace std;

int Cnk(int n, int k, vector<vector<int>> &memo)
{
    if (k == 0 || k == n)
    {
        return 1;
    }
    if (memo[n][k] != -1)
    {
        return memo[n][k];
    }
    memo[n][k] = Cnk(n - 1, k - 1, memo) + Cnk(n - 1, k, memo);
    return memo[n][k];
}
int main()
{

    int n, k;
    cin >> n >> k;
    vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));
    int result = Cnk(n, k, memo);
    cout << result;
}