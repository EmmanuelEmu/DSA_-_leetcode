class Solution {
public:
    bool isIsomorphic(string s, vector<string> t) {
        map<char, string> mp;
        map<string, pair<char, bool>> used;

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

    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        if (pattern.size() != words.size())
            return false;
        return isIsomorphic(pattern, words);
    }
};