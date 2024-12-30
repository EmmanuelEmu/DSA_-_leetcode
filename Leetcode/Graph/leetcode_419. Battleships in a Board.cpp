#include <bits/stdc++.h>
using namespace std;

void bfs(int row, int col, int n, int m, vector<vector<char>> &board, vector<vector<int>> &vis)
{
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    queue<pair<int, int>> q;
    q.push({row, col});
    vis[row][col] = 1; // Mark the starting cell as visited

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + dx[i];
            int ncol = c + dy[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'X')
            {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }
}

int countBattleships(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    int count = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'X' && !vis[i][j])
            {
                bfs(i, j, n, m, board, vis);
                count++;
            }
        }
    }
    return count;
}


int main()
{

    return 0;
}