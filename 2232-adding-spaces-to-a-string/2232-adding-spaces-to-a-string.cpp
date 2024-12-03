class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = s;
        int count = 0;
        for (auto it : spaces) {
            res.insert(it + count, " ");
            count++;
        }
        return res;
    }
};