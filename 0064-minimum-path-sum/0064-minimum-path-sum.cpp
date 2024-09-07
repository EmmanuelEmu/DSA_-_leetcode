class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        // Initialize the first column
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        // Initialize the first row
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        for (auto i = 1; i < m; i++) {
            for (auto j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        for (auto i = 0; i < m; i++) {
            for (auto j = 0; j < n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return dp[m - 1][n - 1];
    }
};