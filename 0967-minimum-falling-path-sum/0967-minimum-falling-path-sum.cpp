class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(matrix.size(),
                               vector<int>(matrix[0].size(), -1));

        for (auto j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (auto row = 1; row < n; row++) {
            for (auto col = 0; col < n; col++) {
                int up = matrix[row][col] + dp[row - 1][col];
                int left =
                    col > 0 ? matrix[row][col] + dp[row - 1][col - 1] : 1e9;
                int right =
                    col < n - 1 ? matrix[row][col] + dp[row - 1][col + 1] : 1e9;

                dp[row][col] = min({up, left, right});
            }
        }

        int minSum = INT_MAX;
        for (auto col = 0; col < n; col++) {
            minSum = min(minSum, dp[n - 1][col]);
        }
        return minSum;
    }
};