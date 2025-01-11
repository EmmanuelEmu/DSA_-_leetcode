class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k)
            return false;
        if (s.size() == k)
            return true;
        unordered_map<char, int> mp;
        for (char c : s)
            mp[c]++;
        int odd = 0;
        for (auto p : mp)
            if (p.second % 2)
                odd++;
        return odd <= k;
    }
};