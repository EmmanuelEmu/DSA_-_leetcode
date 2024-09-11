class Solution {
public:
    // using tabulation method
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (auto j = 0; j < triangle.size(); j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        for (auto i = n - 2; i >= 0; i--) {
            for (auto j = i; j >= 0; j--) {
                int down = triangle[i][j] + dp[i + 1][j];
                int diag = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diag);
            }
        }
        return dp[0][0];
    }
};