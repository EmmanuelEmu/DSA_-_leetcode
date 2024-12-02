class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int maxSize = 0;
        for (auto str : strs) {
            maxSize = max(maxSize, (int)str.size());
        }
        string res = "";
        for (auto i = 0; i < maxSize; i++) {
            char ch = strs[0][i];
            for (auto str : strs) {
                if (str[i] != ch) {
                    return res;
                }
            }
            res += ch;
        }
        return res;
    }
};