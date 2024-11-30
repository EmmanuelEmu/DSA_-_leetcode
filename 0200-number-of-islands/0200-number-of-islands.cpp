class Solution {
public:
    void dfs(int row, int col, int n, int m, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {
        if (row < 0 || col < 0 || row >= n || col >= m ||
            grid[row][col] == '0' || vis[row][col]) {
            return;
        }
        vis[row][col] = 1;
        dfs(row + 1, col, n, m, grid, vis);
        dfs(row - 1, col, n, m, grid, vis);
        dfs(row, col + 1, n, m, grid, vis);
        dfs(row, col - 1, n, m, grid, vis);
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
                    dfs(i, j, n, m, grid, vis);
                }
            }
        }
        return count;
    }
};