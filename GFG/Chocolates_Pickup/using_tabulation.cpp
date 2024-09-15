#include <bits/stdc++.h>
using namespace std;

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));

    // Initialization of the last row
    for (auto j1 = 0; j1 < c; j1++)
    {
        for (auto j2 = 0; j2 < c; j2++)
        {
            if (j1 == j2)
            {
                dp[r - 1][j1][j2] = grid[r - 1][j1];
            }
            else
            {
                dp[r - 1][j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
            }
        }
    }

    // Filling the dp table from the second-last row upwards
    for (auto i = r - 2; i >= 0; i--)
    {
        for (auto j1 = 0; j1 < c; j1++)
        {
            for (auto j2 = 0; j2 < c; j2++)
            {
                int maxi = -1e8;
                for (auto dj1 = -1; dj1 <= +1; dj1++)
                {
                    for (auto dj2 = -1; dj2 <= +1; dj2++)
                    {
                        int value;
                        if (j1 == j2)
                        {
                            value = grid[i][j1];
                        }
                        else
                        {
                            value = grid[i][j1] + grid[i][j2];
                        }

                        // Directly use dp with dj1 and dj2
                        if (j1 + dj1 >= 0 && j1 + dj1 < c && j2 + dj2 >= 0 && j2 + dj2 < c)
                        {
                            value += dp[i + 1][j1 + dj1][j2 + dj2];
                        }
                        else
                        {
                            value += -1e8; // Consider out-of-bounds as an invalid move
                        }

                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][c - 1];
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