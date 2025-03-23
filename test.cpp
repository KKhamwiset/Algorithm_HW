#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubsetSize(int n, vector<int> &arr, int k)
{
    vector<int> dp(k + 1, -1);
    dp[0] = 0;

    for (int num : arr)
    {
        for (int j = k; j >= num; j--)
        {
            if (dp[j - num] != -1)
            {
                dp[j] = max(dp[j], dp[j - num] + 1);
            }
        }
    }
    return (dp[k] == -1 ? 0 : dp[k]);
}

int main()
{
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;

    cout << maxSubsetSize(n, arr, k) << endl;
    return 0;
}