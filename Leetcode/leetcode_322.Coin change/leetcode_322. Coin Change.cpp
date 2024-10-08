#include <bits/stdc++.h>
using namespace std;

int solve(int ind, vector<int> &coins, int amount, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (amount % coins[0] == 0)
        {
            return amount / coins[0];
        }
        else
        {
            return 1e9;
        }
    }
    if (dp[ind][amount] != -1)
    {
        return dp[ind][amount];
    }

    int notTake = 0 + solve(ind - 1, coins, amount, dp);
    int take = INT_MAX;
    if (coins[ind] <= amount)
    {
        take = 1 + solve(ind, coins, amount - coins[ind], dp);
    }
    return dp[ind][amount] = min(take, notTake);
}

int coinChange(vector<int> &coins, int amount)
{
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    int res = solve(coins.size() - 1, coins, amount, dp);
    return res == 1e9 ? -1 : res;
}

int main()
{

    return 0;
}