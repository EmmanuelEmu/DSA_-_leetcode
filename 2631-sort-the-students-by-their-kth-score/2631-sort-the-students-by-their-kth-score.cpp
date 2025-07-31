class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        map<int, vector<int>, greater<int>> mp;
        for (auto vec : score) {
            mp[vec[k]] = vec;
        }
        vector<vector<int>> ans;
        for (auto i : mp) {
            cout << i.first << endl;
            ans.push_back(i.second);
        }
        return ans;
    }
};