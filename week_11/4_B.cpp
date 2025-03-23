#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

long long G_bottomup(int n)
{

    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;

    vector<long long> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] - dp[i - 3];
    }

    return dp[n];
}

int main()
{
    int n = 7;

    long long result = G_bottomup(n);

    cout << "\n G(" << n << ") = " << result << endl;

    return 0;
}