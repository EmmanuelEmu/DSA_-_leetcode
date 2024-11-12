class Solution {
public:
    string longestCommonSubstring(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        int ans = 0;
        int end_index =
            0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    int original_start = i - dp[i][j];
                    int reversed_start = m - j;

                    if (original_start == reversed_start && dp[i][j] > ans) {
                        ans = dp[i][j];
                        end_index = i - 1;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return text1.substr(end_index - ans + 1, ans);
    }

    string longestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return longestCommonSubstring(s, t);
    }
};