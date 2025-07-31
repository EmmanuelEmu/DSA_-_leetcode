class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }

        string modified_order = "";
        map<char, int> orderCharIndex;
        for (int i = 0; i < order.size(); i++) {
            orderCharIndex[order[i]] = i;
        }

        for (auto chr : order) {
            if (mp.find(chr) != mp.end()) {
                modified_order +=
                    string(mp[chr], chr);
                mp.erase(chr);
            }
        }
        for (auto& pair : mp) {
            modified_order += string(pair.second, pair.first);
        }

        return modified_order;
    }
};