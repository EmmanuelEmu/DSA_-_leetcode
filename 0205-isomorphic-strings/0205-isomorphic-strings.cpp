class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mp;
        vector<pair<char, bool>> used(256, pair<char, bool>(-1, false));

        if (s.size() != t.size())
            return false;

        for (int i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) != mp.end()) {
                if (mp[s[i]] != t[i] ||
                    (used[t[i]].second == true && used[t[i]].first != s[i]))
                    return false;
            } else {
                if (used[t[i]].second == false) {
                    mp[s[i]] = t[i];
                    used[t[i]].first = s[i];
                    used[t[i]].second = true;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};