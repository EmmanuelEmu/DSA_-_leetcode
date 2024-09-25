class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;

        for (auto it : s) {
            res ^= it;
        }
        for (auto it1 : t) {
            res ^= it1;
        }
        return res;
    }
};