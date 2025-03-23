#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &memo, int i)
{
    if (i < 0)
    {
        return 0;
    }
    if (i == 0 || i == 1)
    {
        return 1;
    }
    if (memo[i] != -1)
    {
        return memo[i];
    }
    memo[i] = solve(memo, i - 1) * 3 + solve(memo, i - 2);
    return memo[i];
}
int main()
{
    int n;
    cin >> n;
    vector<int> memo(n + 1, -1);
    cout << solve(memo, n - 1);
}