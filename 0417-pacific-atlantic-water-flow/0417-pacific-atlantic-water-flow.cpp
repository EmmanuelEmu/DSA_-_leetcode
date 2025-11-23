class Solution {
public:
    void dfsAtlantic(int i, int j, int n, int m, vector<vector<int>>& heights,
                     vector<vector<bool>>& visited,
                     vector<pair<int, int>>& directions,
                     vector<vector<bool>>& isAtlanticPossible) {
        visited[i][j] = true;
        isAtlanticPossible[i][j] = true;

        for (auto dir : directions) {
            int newI = i + dir.first;
            int newJ = j + dir.second;

            if (newI >= 0 && newI < n && newJ >= 0 && newJ < m &&
                !visited[newI][newJ] &&
                heights[newI][newJ] >= heights[i][j]) // FIXED condition
            {
                dfsAtlantic(newI, newJ, n, m, heights, visited, directions,
                            isAtlanticPossible);
            }
        }
    }

    void dfsPacific(int i, int j, int n, int m, vector<vector<int>>& heights,
                    vector<vector<bool>>& visited,
                    vector<pair<int, int>>& directions,
                    vector<vector<bool>>& isPacificPossible) {
        visited[i][j] = true;
        isPacificPossible[i][j] = true;

        for (auto dir : directions) {
            int newI = i + dir.first;
            int newJ = j + dir.second;

            if (newI >= 0 && newI < n && newJ >= 0 && newJ < m &&
                !visited[newI][newJ] &&
                heights[newI][newJ] >= heights[i][j]) // FIXED condition
            {
                dfsPacific(newI, newJ, n, m, heights, visited, directions,
                           isPacificPossible);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        vector<vector<int>> result;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // FIXED: use only 4 directions
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // ---------- Pacific border ----------
        for (int j = 0; j < m; j++) {
            dfsPacific(0, j, n, m, heights, visited, directions, pacific);
        }
        for (int i = 0; i < n; i++) {
            dfsPacific(i, 0, n, m, heights, visited, directions, pacific);
        }

        // reset visited
        visited = vector<vector<bool>>(n, vector<bool>(m, false));

        // ---------- Atlantic border ----------
        for (int j = 0; j < m; j++) {
            dfsAtlantic(n - 1, j, n, m, heights, visited, directions, atlantic);
        }
        for (int i = 0; i < n; i++) {
            dfsAtlantic(i, m - 1, n, m, heights, visited, directions, atlantic);
        }

        // collect result
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};