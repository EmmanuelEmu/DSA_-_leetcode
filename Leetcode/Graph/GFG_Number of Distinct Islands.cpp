#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &visited, vector<pair<int, int>> &vec, int r, int c)
{
    visited[row][col] = 1;
    vec.push_back({row - r, col - c});
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    for (auto i = 0; i < 4; i++)
    {
        int nrow = row + dx[i];
        int ncol = col + dy[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
        {
            dfs(nrow, ncol, n, m, grid, visited, vec, r, c);
        }
    }
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    // code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;

    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j] == 1)
            {
                vector<pair<int, int>> vec;
                dfs(i, j, n, m, grid, visited, vec, i, j);
                st.insert(vec);
            }
        }
    }

    return st.size();
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid;
    for (auto i = 0; i < n; i++)
    {
        vector<int> row;
        for (auto j = 0; j < m; j++)
        {
            int val;
            cin >> val;
            row.push_back(val);
        }
        grid.push_back(row);
    }
    cout << countDistinctIslands(grid) << endl;
    return 0;
}