class Solution {
public:
    // using bfs
    void bfs(int row, int col, int n, int m, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        // Movement in 4 cardinal directions
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int curRow = q.front().first;
            int curCol = q.front().second;
            q.pop();

            for (auto dir : directions) {
                int nrow = curRow + dir.first;
                int ncol = curCol + dir.second;

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    count++;
                    bfs(i, j, n, m, grid, vis);
                }
            }
        }
        return count;
    }
};