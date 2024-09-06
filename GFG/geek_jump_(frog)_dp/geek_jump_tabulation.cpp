#include <bits/stdc++.h>
using namespace std;

int minimumEnergy(vector<int> &height, int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (auto i = 1; i <=n; i++)
    {
        int left = dp[i - 1] + abs(height[i] - height[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            right = dp[i - 2] + abs(height[i] - height[i - 2]);
        }
        dp[i] = min(left, right);
    }

    return dp[n-1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec;
    while (n--)
    {
        int a;
        cin >> a;
        vec.push_back(a);
    }

    cout << minimumEnergy(vec, vec.size()-1) << endl;
    return 0;
}