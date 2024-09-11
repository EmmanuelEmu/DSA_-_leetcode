class Solution {
public:
    bool solve(string& s, string& t, int i, int ind, int n,
               vector<vector<int>>& dp) {
        if (i == s.size()) {
            return true;
        }

        if (ind == n) {
            return false;
        }
        if (dp[i][ind] != -1) {
            return dp[i][ind];
        }

        // If the current characters match, try to match the next character in
        // both 's' and 't'
        if (s[i] == t[ind]) {
            return dp[i][ind] = solve(s, t, i + 1, ind + 1, n, dp);
        }

        return dp[i][ind] = solve(s, t, i, ind + 1, n, dp);
    }

    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(
            s.size() + 1, vector<int>(t.size() + 1, -1));
        return solve(s, t, 0, 0, t.size(), dp);
    }
};