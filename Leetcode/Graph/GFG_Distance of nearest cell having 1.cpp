#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> res(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;

    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        res[row][col] = dist;

        for (auto i = 0; i < 4; i++)
        {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol])
            {
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, dist + 1});
            }
        }
    }

    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat;
    for (auto i = 0; i < n; i++)
    {
        vector<int> row;
        for (auto j = 0; j < m; j++)
        {
            int val;
            cin >> val;
            row.push_back(val);
        }
        mat.push_back(row);
    }
    vector<vector<int>> res = nearest(mat);
    for (auto it : res)
    {
        for (auto it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }
    return 0;
}