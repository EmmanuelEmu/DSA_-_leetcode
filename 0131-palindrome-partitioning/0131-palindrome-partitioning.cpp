class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    vector<vector<string>> solve(int ind, string s, vector<string>& path,
                                 vector<vector<vector<string>>>& dp) {
        if (ind == s.size()) {
            return {{}};
        }

        if (!dp[ind].empty()) {
            return dp[ind];
        }

        vector<vector<string>> result;

        for (int i = ind; i < s.size(); i++) {
            if (isPalindrome(s, ind, i)) {
                string palinSubstring = s.substr(ind, i - ind + 1);
                vector<vector<string>> temp = solve(i + 1, s, path, dp);

                // Append current palindrome to all partitions
                for (auto& subList : temp) {
                    subList.insert(subList.begin(), palinSubstring);
                    result.push_back(subList);
                }
            }
        }

        return dp[ind] = result;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<vector<string>>> dp(s.size());
        vector<string> path;
        return solve(0, s, path, dp);
    }
};