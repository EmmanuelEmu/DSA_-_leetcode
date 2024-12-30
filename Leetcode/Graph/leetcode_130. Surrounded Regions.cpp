#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, int n, int m, vector<vector<char>> &board, vector<vector<int>> &vis, int delRow[], int delCol[])
{
    vis[row][col] = 1;
    for (auto i = 0; i < 4; i++)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O')
        {
            dfs(nrow, ncol, n, m, board, vis, delRow, delCol);
        }
    }
}

void solve(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, -1, 0, 1};
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (auto j = 0; j < m; j++)
    {
        if (board[0][j] == 'O')
            dfs(0, j, n, m, board, vis, delRow, delCol);
        if (board[n - 1][j] == 'O')
            dfs(n - 1, j, n, m, board, vis, delRow, delCol);
    }

    for (auto i = 0; i < n; i++)
    {
        if (board[i][0] == 'O')
            dfs(i, 0, n, m, board, vis, delRow, delCol);
        if (board[i][m - 1] == 'O')
            dfs(i, m - 1, n, m, board, vis, delRow, delCol);
    }

    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < m; j++)
        {
            if (!vis[i][j] && board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
        }
    }
}

int main()
{

    return 0;
}