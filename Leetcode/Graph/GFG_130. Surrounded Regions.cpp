#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, int n, int m, vector<vector<char>> &board)
{
    if (row < 0 || col < 0 || row >= n || col >= m || board[row][col] != 'O')
    {
        return;
    }
    board[row][col] = '#';
    dfs(row + 1, col, n, m, board);
    dfs(row - 1, col, n, m, board);
    dfs(row, col + 1, n, m, board);
    dfs(row, col - 1, n, m, board);
}

void solve(vector<vector<char>> &board)
{
    int n = board.size();
    if (n == 0) return;
    int m = board[0].size();

    for (int i = 0; i < n; i++)
    {
        if (board[i][0] == 'O') dfs(i, 0, n, m, board);    
        if (board[i][m - 1] == 'O') dfs(i, m - 1, n, m, board);
    }
    for (int j = 0; j < m; j++)
    {
        if (board[0][j] == 'O') dfs(0, j, n, m, board); 
        if (board[n - 1][j] == 'O') dfs(n - 1, j, n, m, board);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'O') board[i][j] = 'X';
            if (board[i][j] == '#') board[i][j] = 'O';
        }
    }
}



int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board;
    for (int i = 0; i < n; i++)
    {
        vector<char> row;
        for (int j = 0; j < m; j++)
        {
            char val;
            cin >> val;
            row.push_back(val);
        }
        board.push_back(row);
    }
    solve(board);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}