#include <iostream>
#include <vector>

using namespace std;

int DP(int i, int m, vector<int> &memo)
{
    if (i == 0)
    {
        return 1;
    }
    if (i < 0)
    {
        return 0;
    }

    if (memo[i] != -1)
    {
        return memo[i];
    }
    memo[i] = 0;
    for (int j = 1; j <= m; j++)
    {
        memo[i] += DP(i - j, m, memo);
    }
    return memo[i];
}
int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> memo(n + 1, -1);

    int result = DP(n, m, memo);

    cout << result << endl;

    return 0;
}