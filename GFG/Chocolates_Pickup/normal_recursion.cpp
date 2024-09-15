#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j1, int j2, int row, int col, vector<vector<int>> &grid)
{

    if ((j1 < 0 || j1 >= col) || (j2 < 0 || j2 >= col))
    {
        return -1e8;
    }

    if (i == row - 1)
    {
        if (j1 == j2)
        {
            return grid[i][j1];
        }
        else
        {
            return grid[i][j1] + grid[i][j2];
        }
    }

    int maxi = -1e8;
    for (auto dj1 = -1; dj1 <= +1; dj1++)
    {
        for (auto dj2 = -1; dj2 <= +1; dj2++)
        {
            if (j1 == j2)
            {
                maxi = max(maxi, grid[i][j1] + solve(i + 1, j1 + dj1, j2 + dj2, row, col, grid));
            }
            else
            {
                maxi = max(maxi, grid[i][j1] + grid[i][j2] + solve(i + 1, j1 + dj1, j2 + dj2, row, col, grid));
            }
        }
    }

    return maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    int n = grid.size();
    return solve(0, 0, c - 1, r, c, grid);
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int result = maximumChocolates(n, m, grid);
    cout << result << endl;
    return 0;
}