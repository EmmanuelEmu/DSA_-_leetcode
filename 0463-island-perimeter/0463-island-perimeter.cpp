class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid,
             vector<vector<int>>& visited, int& count, vector<int> delRow,
             vector<int> delCol) {
        visited[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if (nRow < 0 || nRow >= grid.size() || nCol < 0 ||
                nCol >= grid[0].size() || grid[nRow][nCol] == 0) {
                count++;
            }
        }

        for (int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if (nRow >= 0 && nRow < grid.size() && nCol >= 0 &&
                nCol < grid[0].size() && grid[nRow][nCol] == 1 &&
                visited[nRow][nCol] == 0) {
                dfs(nRow, nCol, grid, visited, count, delRow, delCol);
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(),
                                    vector<int>(grid[0].size(), 0));
        int count = 0;
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1 && visited[row][col] == 0) {
                    dfs(row, col, grid, visited, count, delRow, delCol);
                }
            }
        }
        return count;
    }
};