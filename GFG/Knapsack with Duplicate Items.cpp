#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int W, int val[], int wt[], vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return ((int)W/wt[0]) * val[0];
    }
    if (dp[ind][W] != -1)
    {
        return dp[ind][W];
    }
    int notTake = 0 + solve(ind - 1, W, val, wt, dp);
    int take = INT_MIN;
    if (wt[ind] <= W)
    {
        take = val[ind] + solve(ind, W - wt[ind], val, wt, dp);
    }
    return dp[ind][W] = max(take, notTake);
}

int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(N, vector<int>(W+1, -1)) ;
    return solve(N - 1, W, val, wt, dp);
}

int main()
{

    return 0;
}