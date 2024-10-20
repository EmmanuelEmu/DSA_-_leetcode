class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for (auto i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (auto j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }
        for (auto i = 1; i <= n; i++) {
            for (auto j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        return n + m - 2 * longestCommonSubsequence(word1, word2);
    }
};