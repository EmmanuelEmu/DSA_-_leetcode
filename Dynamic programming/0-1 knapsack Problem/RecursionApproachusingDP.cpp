#include <bits/stdc++.h>
using namespace std;


/*
4
1 5
2 4
4 8
5 6
5
*/

int solve(vector<int> wt, vector<int> val, int W, int ind, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (wt[0] <= W)
        {
            return val[0];
        }
        return 0;
    }
    if (dp[ind][W] != -1)
    {
        return dp[ind][W];
    }
    int notTake = solve(wt, val, W, ind - 1, dp);
    int take = INT_MIN;
    if (wt[ind] <= W)
    {
        take = val[ind] + solve(wt, val, W - wt[ind], ind - 1, dp);
    }
    return dp[ind][W] = max(take, notTake);
}

int knapSack(vector<int> wt, vector<int> val, int W)
{
    vector<vector<int>> dp(wt.size(), vector<int>(W + 1, -1));
    return solve(wt, val, W, wt.size() - 1, dp);
}

int main()
{

    int n;
    vector<int> v;
    vector<int> wt;
    cin >> n;
    while (n--)
    {
        int val, weight;
        cin >> weight >> val;
        v.push_back(val);
        wt.push_back(weight);
    }
    int W;
    cin >> W;
    cout << knapSack(wt, v, W) << endl;
    return 0;
}