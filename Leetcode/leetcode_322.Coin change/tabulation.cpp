#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));
    for (int tar = 0; tar <= amount; tar++)
    {
        if (tar % coins[0] == 0)
        {
            dp[0][tar] = tar / coins[0];
        }
        else
        {
            dp[0][tar] = 1e9;
        }
    }
    for(int ind = 1; ind < coins.size(); ind){
        for(int tar = 0; tar <= amount; tar++){
            int notTake = 0 + dp[ind-1][tar];
            int take = INT_MAX;
            if(coins[ind] <= tar){
                take = 1 + dp[ind][tar-coins[ind]];
            }
            dp[ind][tar] = min(take, notTake);
        }
    }

    return dp[coins.size() - 1][amount] >= 1e9 ? -1 : dp[coins.size() - 1][amount];
}

int main()
{

    return 0;
}