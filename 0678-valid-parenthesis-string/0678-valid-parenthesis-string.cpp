class Solution {
public:
    bool solve(int ind, string& s, int count, vector<vector<int>> &dp) {
        if (count < 0) {
            return false;
        }
        if (ind == s.size()) {
            return count == 0;
        }
        if(dp[ind][count]!=-1) return dp[ind][count];
        if (s[ind] == '(') {
            return solve(ind + 1, s, count + 1, dp);
        }
        if (s[ind] == ')') {
            return solve(ind + 1, s, count - 1, dp);
        }

        return dp[ind][count] = solve(ind + 1, s, count, dp) || solve(ind + 1, s, count + 1, dp) ||
               solve(ind + 1, s, count - 1, dp);
    }

    bool checkValidString(string s) { 
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, s, 0, dp); 
    }
};