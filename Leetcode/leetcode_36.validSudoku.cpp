#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>> &board, int row, int col, char c)
{
    for (auto i = 0; i < board.size(); i++)
    {
        if (board[row][i] == c)
        {
            return false;
        }

        if (board[i][col] == c)
        {
            return false;
        }

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
        {
            return false;
        }
    }

    return true;
}

bool solve(vector<vector<char>> &board)
{
    for (auto i = 0; i < 9; i++)
    {
        for (auto j = 0; j < 9; j++)
        {
            char current = board[i][j];
            if (current != '.')
            {
                board[i][j] = '.';
                if (!isValid(board, i, j, current))
                {
                    return false;
                }
                board[i][j] = current;
            }
        }
    }
    return true;
}

bool solveSudoku(vector<vector<char>> &board)
{
    return solve(board);
}

int main()
{
    vector<vector<char>> sudoku;
    for (auto i = 0; i < 9; i++)
    {
        vector<char> singleRow;
        char item;
        for (auto j = 0; j < 9; j++)
        {
            cin >> item;
            singleRow.push_back(item);
        }
        sudoku.push_back(singleRow);
    }

    cout << solveSudoku(sudoku) << endl;
    for (auto row : sudoku)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}