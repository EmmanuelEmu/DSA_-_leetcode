class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n == 0) {
            return 0;
        }
        if (n < 0) {
            return INT_MAX;
        }
        if (dp[n] != -1) {
            return dp[n];
        }

        int minSquares = INT_MAX;
        for (auto i = 1; i <= sqrt(n); i++) {
            int result = 1 + solve(n - i * i, dp);
            if (result != INT_MAX) {
                minSquares = min(minSquares, result);
            }
        }
        dp[n] = minSquares;
        return dp[n];
    }
    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};