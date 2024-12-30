#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp, int fee)
{
    if (ind >= prices.size())
    {
        return 0; // No more profit can be made
    }

    if (dp[ind][buy] != -1)
    {
        return dp[ind][buy];
    }

    int profit = 0;
    if (buy)
    {
        // Option to buy or skip
        profit = max(-prices[ind] - fee + solve(ind + 1, 0, prices, dp, fee),
                     solve(ind + 1, 1, prices, dp, fee));
    }
    else
    {
        // Option to sell or skip
        profit = max(prices[ind] + solve(ind + 1, 1, prices, dp, fee), // Cooldown applied
                     solve(ind + 1, 0, prices, dp, fee));
    }

    return dp[ind][buy] = profit;
}

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solve(0, 1, prices, dp, fee);
}

int main()
{

    return 0;
}