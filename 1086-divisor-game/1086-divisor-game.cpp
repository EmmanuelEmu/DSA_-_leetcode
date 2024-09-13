class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n == 1) {
            return 0;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        for (auto i = 1; i < n; i++) {
            if (n % i == 0) {
                if (solve(n - i, dp) == 0) {
                    return dp[n] = 1;
                }
            }
        }
        dp[n] = 0;
        return dp[n];
    }

    bool divisorGame(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};