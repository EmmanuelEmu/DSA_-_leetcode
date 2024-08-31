#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> board, int n){
    int tempRow = row;
    int tempCol = col;

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

int totalNQueens(int n){
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    
    solve(0, board, ans, n);
    return ans.size();
}

int main(){

    int n;
    cin >> n;

    int res = totalNQueens(n);

    cout << res << endl;
    
    return 0;
}