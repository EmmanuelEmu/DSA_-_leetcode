#include <bits/stdc++.h>
using namespace std;

int DP(vector<int> &height, int n, vector<int> dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int left = DP(height, n - 1, dp) + abs(height[n] - height[n - 1]);

    int right = INT_MAX;
    if (n > 1)
    {
        right = DP(height, n - 2, dp) + abs(height[n] - height[n - 2]);
    }

    return dp[n] = min(left, right);
}

int minimumEnergy(vector<int> &height, int n)
{
    vector<int> dp(n + 1, -1);
    return DP(height, n - 1, dp);
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec;
    while (n--)
    {
        int a;
        vec.push_back(a);
    }
    
    cout << minimumEnergy(vec, vec.size());
    return 0;
}