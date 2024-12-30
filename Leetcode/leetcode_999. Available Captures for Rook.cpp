#include <bits/stdc++.h>
using namespace std;

int attacks(int row, int col, vector<vector<char>> &board)
{
    int count = 0;
    int n = board.size();
    int m = board[0].size();
    for (auto i = row + 1; i < n; i++)
    {
        if (board[i][col] == 'p')
        {
            count++;
            break;
        }
        else if (board[i][col] == 'B')
        {
            break;
        }
    }
    for (auto i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == 'p')
        {
            count++;
            break;
        }
        else if (board[i][col] == 'B')
        {
            break;
        }
    }
    for (auto i = col + 1; i < m; i++)
    {
        if (board[row][i] == 'p')
        {
            count++;
            break;
        }
        else if (board[row][i] == 'B')
        {
            break;
        }
    }
    for (auto i = col - 1; i >= 0; i--)
    {
        if (board[row][i] == 'p')
        {
            count++;
            break;
        }
        else if (board[row][i] == 'B')
        {
            break;
        }
    }

    return count;
}

int numRookCaptures(vector<vector<char>> &board)
{
    int count;
    int n = board.size();
    int m = board[0].size();
    int row = -1, col = -1;
    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < m; j++)
        {
            if (board[i][j] == 'R')
            {
                row = i;
                col = j;
                break;
            }
        }
    }
    count = attacks(row, col, board);
    return count;
}

int main()
{

    return 0;
}