class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int, int> soldierCount; // row index -> number of soldiers
        for (int i = 0; i < mat.size(); i++) {
            int count = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) {
                    count++;
                } else {
                    break; // since soldiers are always before civilians
                }
            }
            soldierCount[i] = count;
        }
        vector<pair<int, int>> weakRow;
        for (auto& entry : soldierCount) {
            weakRow.push_back(
                {entry.second, entry.first}); // (number of soldiers, row index)
        }
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        };
        sort(weakRow.begin(), weakRow.end(), cmp);
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(weakRow[i].second);
        }
        return result;
    }
};