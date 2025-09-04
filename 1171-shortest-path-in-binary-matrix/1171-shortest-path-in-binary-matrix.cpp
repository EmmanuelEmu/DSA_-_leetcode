class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return -1;
        if(n==1 && m==1) return 1;
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        vector<int> dRow = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dCol = {-1, 0, 1, -1, 1, -1, 0, 1};
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 1;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for (int i = 0; i < 8; i++) {
                int nr = r + dRow[i];
                int nc = c + dCol[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    grid[nr][nc] == 0 && dis + 1 < dist[nr][nc]) {
                    dist[nr][nc] = dis + 1;
                    if (nr == n - 1 && nc == m - 1)
                        return dis + 1;
                    q.push({dis + 1, {nr, nc}});
                }
            }
        }
        return -1;
    }
};