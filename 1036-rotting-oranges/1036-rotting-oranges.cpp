class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxTime = 0;
        int totalOranges = 0;
        int rottenOranges = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    rottenOranges++;
                    vis[i][j] = 1;
                }
                if (grid[i][j] > 0) {
                    totalOranges++;
                }
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            maxTime = max(maxTime, time);
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] != 1 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, time + 1});
                    vis[nrow][ncol] = 1;
                    grid[nrow][ncol] = 2;
                    rottenOranges++;
                }
            }
        }

        if (rottenOranges != totalOranges) return -1;
        return maxTime;
    }
};
