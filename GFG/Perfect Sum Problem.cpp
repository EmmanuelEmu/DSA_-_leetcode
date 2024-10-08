#include <bits/stdc++.h>
using namespace std;


int perfectSum(int arr[], int n, int sum)
{
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    if (arr[0] <= sum)
    {
        dp[0][arr[0]] = 1;
    }
    // Special case if the first element is 0: both picking and not picking the 0 results in valid subsets
    if (arr[0] == 0)
    {
        dp[0][0] = 2;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            int notPick = dp[i - 1][j]; 
            int pick = 0;
            if (arr[i] <= j)
            {
                pick = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = (pick + notPick)%MOD;
        }
    }

    return dp[n - 1][sum];
}

int main()
{

    return 0;
}