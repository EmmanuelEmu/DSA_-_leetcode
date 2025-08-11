class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {

        vector<pair<int, int>> rowOnesZeros;
        vector<pair<int, int>> colOnesZeros;
        int n = grid.size();
        int m = grid[0].size();
        int ones = 0;
        int zeros = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    ones++;
                } else {
                    zeros++;
                }
            }
            rowOnesZeros.push_back({ones, zeros});
            ones = 0;
            zeros = 0;
        }

        ones = 0;
        zeros = 0;
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == 1) {
                    ones++;
                } else {
                    zeros++;
                }
            }
            colOnesZeros.push_back({ones, zeros});
            ones = 0;
            zeros = 0;
        }

        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = rowOnesZeros[i].first - rowOnesZeros[i].second +
                            colOnesZeros[j].first - colOnesZeros[j].second;
            }
        }
        return res;
    }
};