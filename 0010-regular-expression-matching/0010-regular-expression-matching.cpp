class Solution {
public:
    bool solve(int ind1, int ind2, string& s, string& p,
               vector<vector<int>>& dp) {
        if (ind2 == p.size())
            return ind1 == s.size();
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        // Check if characters match or if there's a '.' in the pattern
        bool match =
            (ind1 < s.size() && (s[ind1] == p[ind2] || p[ind2] == '.'));

        // Handle the '*' character in the pattern
        if (ind2 + 1 < p.size() && p[ind2 + 1] == '*') {
            // Case 1: '*' matches zero occurrences of the preceding element
            bool skipStar = solve(ind1, ind2 + 2, s, p,
                                  dp); // Skip the preceding element and '*'
            // Case 2: '*' matches one or more occurrences of the preceding
            // element
            bool matchStar =
                match && solve(ind1 + 1, ind2, s, p,
                               dp); // Move string pointer, keep pattern
            dp[ind1][ind2] = skipStar || matchStar;
        } else if (match) {
            dp[ind1][ind2] = solve(ind1 + 1, ind2 + 1, s, p, dp);
        } else {
            dp[ind1][ind2] = false;
        }
        return dp[ind1][ind2];
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(0, 0, s, p, dp);
    }
};