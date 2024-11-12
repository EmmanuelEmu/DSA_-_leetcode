class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {

        sort(items.begin(), items.end());

        // Cumulative maximum beauty finding
        for (int i = 1; i < items.size(); i++) {
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }

        vector<int> res;
        for (int q : queries) {
            int lb = 0, ub = items.size() - 1, maxi = 0;
            while (lb <= ub) {
                int mid = lb + (ub - lb) / 2;
                if (items[mid][0] <= q) {
                    maxi = items[mid][1];
                    lb = mid + 1;
                } else {
                    ub = mid - 1;
                }
            }

            res.push_back(maxi);
        }
        return res;
    }
};