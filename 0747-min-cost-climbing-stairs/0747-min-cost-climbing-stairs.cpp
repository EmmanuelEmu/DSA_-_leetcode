class Solution {
public:

    // Using tabulation method
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(cost.size(), -1);
        dp[n - 1] = cost[n - 1];
        dp[n - 2] = cost[n - 2];
        for (auto i = n - 3; i >= 0; i--) {
            int oneStep = cost[i] + dp[i + 1];
            int twoStep = cost[i] + dp[i + 2];
            dp[i] = min(oneStep, twoStep);
        }
        return min(dp[0], dp[1]);
    }
};