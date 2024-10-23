class Solution {
public:
    int solve(int ind, int buy, vector<int>& prices,
              vector<vector<vector<int>>>& dp, int trans) {
        if (ind == prices.size() || trans == 2) {
            return 0; // No more profit can be made
        }

        if (dp[ind][buy][trans] != -1) {
            return dp[ind][buy][trans];
        }

        int profit = 0;
        if (buy) {
            // Option to buy or skip
            profit = max(-prices[ind] + solve(ind + 1, 0, prices, dp, trans),
                         solve(ind + 1, 1, prices, dp, trans));
        } else {
            // Option to sell or skip
            profit = max(prices[ind] + solve(ind + 1, 1, prices, dp, trans + 1),
                         solve(ind + 1, 0, prices, dp, trans));
        }

        return dp[ind][buy][trans] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(2, -1)));
        return solve(
            0, 1, prices, dp,
            0); // Start at index 0, buy allowed, 0 transactions completed
    }
};