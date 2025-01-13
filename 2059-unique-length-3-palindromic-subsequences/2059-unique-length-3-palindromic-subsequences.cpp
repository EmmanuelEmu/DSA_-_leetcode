class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_map<char, pair<int, int>> mp;
        for (char c = 'a'; c <= 'z'; c++) {
            mp[c] = {-1, -1};
        }
        for (auto i = 0; i < n; i++) {
            if (mp[s[i]].first == -1) {
                mp[s[i]].first = i;
            }
        }
        for (auto i = n - 1; i >= 0; i--) {
            if (mp[s[i]].second == -1) {
                mp[s[i]].second = i;
            }
        }
        int ans = 0;
        for (auto it : mp) {
            char c = it.first;
            int start = it.second.first;
            int end = it.second.second;
            if (start == -1 || end == -1) {
                continue;
            }
            unordered_set<char> st;
            for (auto i = start + 1; i < end; i++) {
                st.insert(s[i]);
            }
            ans += st.size();
        }
        return ans;
    }
};