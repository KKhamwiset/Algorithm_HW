#include <iostream>
#include <vector>
using namespace std;

long long G_topdown(int n, vector<long long> &memo)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 1;

    if (memo[n] != -1)
    {
        return memo[n];
    }

    memo[n] = G_topdown(n - 1, memo) + G_topdown(n - 2, memo) - G_topdown(n - 3, memo);

    return memo[n];
}

int main()
{
    int n = 7;

    vector<long long> memo(n + 1, -1);

    cout << "G(" << n << ") = " << G_topdown(n, memo) << endl;

    return 0;
}