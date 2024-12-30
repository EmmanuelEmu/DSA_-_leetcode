#include <bits/stdc++.h>
using namespace std;

int numEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < m; j++)
        {
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid[i][j] == 1)
            {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, -1, 0, 1};
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (auto i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                q.push({nrow, ncol});
                visited[nrow][ncol] = 1;
            }
        }
    }
    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j] == 1)
            {
                count++;
            }
        }
    }
    return count;
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
    cout << numEnclaves(grid) << endl;
    return 0;
}