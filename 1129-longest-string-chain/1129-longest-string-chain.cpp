class Solution {
public:
    bool checkValid(string& a, string& b) {
        if (a.size() != b.size() + 1) {
            return false;
        }
        int first = 0, second = 0;
        while (first < a.size()) {
            if (second < b.size() && a[first] == b[second]) {
                first++;
                second++;
            } else {
                first++;
            }
        }
        if (first == a.size() && second == b.size()) {
            return true;
        }
        return false;
    }

    static bool compareStr(string& a, string& b) { return a.size() < b.size(); }

    int longestStrChain(vector<string>& words) {
        // Code here
        int n = words.size();
        sort(words.begin(), words.end(), compareStr);
        vector<int> dp(n, 1);
        int maxi = 1;
        // int hash[n];
        int lastIndex = 0;
        for (auto i = 0; i < n; i++) {
            // hash[i] = i;
            for (auto j = 0; j < i; j++) {
                if (checkValid(words[i], words[j]) && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    // hash[i] = j;
                }
            }
            if (maxi < dp[i]) {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        return maxi;
    }
};