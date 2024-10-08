#include <bits/stdc++.h>
using namespace std;

int solve(int ind, vector<int> &coins, int amount, vector<vector<int>> &dp)
{
    if (amount == 0)
    {
        return 1;
    }
    if (ind == 0)
    {
        if (amount % coins[0] == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (dp[ind][amount] != -1)
    {
        return dp[ind][amount];
    }

    int notTake = solve(ind - 1, coins, amount, dp);
    int take = 0;
    if (coins[ind] <= amount)
    {
        take = solve(ind, coins, amount - coins[ind], dp);
    }
    return dp[ind][amount] = take + notTake;
}

int change(int amount, vector<int> &coins)
{
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    return solve(coins.size() - 1, coins, amount, dp);
}

int main()
{

    return 0;
}