#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int, int>, int>> orangesRotting;
    int freshOranges = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                orangesRotting.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else if (grid[i][j] == 1)
            {
                freshOranges++;
            }
        }
    }
    int time = 0;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    int rottenOranges = 0;
    while (!orangesRotting.empty())
    {
        int row = orangesRotting.front().first.first;
        int orl = orangesRotting.front().first.second;
        time = max(time, orangesRotting.front().second);
        orangesRotting.pop();

        for (auto i = 0; i < 4; i++)
        {
            int nrow = row + dx[i];
            int ncol = orl + dy[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
            {
                orangesRotting.push({{nrow, ncol}, time + 1});
                vis[nrow][ncol] = 2;
                rottenOranges++;
            }
        }
    }

    if (freshOranges != rottenOranges)
        return -1;
    return time;
}

int main()
{

    return 0;
}