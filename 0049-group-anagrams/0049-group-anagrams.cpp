class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hash;
        for (auto it : strs) {
            string temp = it;
            sort(temp.begin(), temp.end());
            hash[temp].push_back(it);
        }
        for (auto it : hash) {
            res.push_back(it.second);
        }
        return res;
    }
};