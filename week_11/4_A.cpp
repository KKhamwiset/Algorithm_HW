#include <iostream>
#include <vector>
using namespace std;

long long F_bottomup(int n, int k)
{

    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = 1;
    }

    for (int i = 1; i <= min(n, k); i++)
    {
        dp[i][i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= min(i, k); j++)
        {

            if (i == j)
            {
                continue;
            }

            if (j >= 2)
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 2];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][k];
}

int main()
{
    int n = 6, k = 4;

    cout << "F(" << n << ", " << k << ") = " << F_bottomup(n, k) << endl;

    return 0;
}