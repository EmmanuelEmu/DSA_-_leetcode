class Solution {
public:
    int solve(int ind, int buy, vector<int>& prices,
              vector<vector<vector<int>>>& dp, int trans, int k) {
        if (ind == prices.size() || trans == k) {
            return 0; // No more profit can be made
        }

        if (dp[ind][buy][trans] != -1) {
            return dp[ind][buy][trans];
        }

        int profit = 0;
        if (buy) {
            // Option to buy or skip
            profit = max(-prices[ind] + solve(ind + 1, 0, prices, dp, trans, k),
                         solve(ind + 1, 1, prices, dp, trans, k));
        } else {
            // Option to sell or skip
            profit =
                max(prices[ind] + solve(ind + 1, 1, prices, dp, trans + 1, k),
                    solve(ind + 1, 0, prices, dp, trans, k));
        }

        return dp[ind][buy][trans] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(0, 1, prices, dp, 0, k);
    }
};