#include<bits/stdc++.h>
using namespace std;



/*
Test Case
5 3 . . 7 . . . . 
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9
*/


bool isSafe(int row, int col, vector<string> board, int n){
    int tempRow = row;
    int tempCol = col;

    // upper diagonal
    while (tempRow >=0 && tempCol >=0)
    {
        if (board[tempRow][tempCol] == 'Q')
        {
            return false;
        }
        tempRow --;
        tempCol --;
    }

    tempRow = row;
    tempCol = col;

    // row checking
    while (tempCol >=0)
    {
        if (board[tempRow][tempCol] == 'Q')
        {
            return false;
        }
        tempCol -- ;
    }
    

    tempRow = row;
    tempCol = col;
    // lower diagonal
    while (tempRow <n && tempCol >=0)
    {
        if (board[tempRow][tempCol] == 'Q')
        {
            return false;
        }
        tempRow ++;
        tempCol --;
    }

    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    
    for (auto row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col+1, board, ans, n);
            board[row][col] = '.';
        }
        
    }
    
}

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    
    solve(0, board, ans, n);
    return ans;
}

int main(){

    int n;
    cin >> n;

    vector<vector<string>> res = solveNQueens(n);

     for (auto &vec : res) {
        for (auto &row : vec) {
            for (char c : row) {
                cout << c << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    return 0;
}