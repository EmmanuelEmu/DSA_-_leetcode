class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    res[i][j] = 0;
                }
            }
        }

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    if (res[nrow][ncol] > res[row][col] + 1) {
                        res[nrow][ncol] = res[row][col] + 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }

        return res;
    }
};