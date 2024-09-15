#include<bits/stdc++.h>
using namespace std;


int solve(int row, int col, vector<vector<int>> &dungeon, vector<vector<int>> &dp, int n, int m) {
    
    if (row == n - 1 && col == m - 1) {
        return max(1, 1 - dungeon[row][col]);
    }
    if (row >= n || col >= m) {
        return 1e9;
    }
    
    if (dp[row][col] != -1) {
        return dp[row][col];
    }
    
    int rightWard = solve(row, col + 1, dungeon, dp, n, m);
    int downWard = solve(row + 1, col, dungeon, dp, n, m);
    
    int healthRequired = min(rightWard, downWard) - dungeon[row][col];
    return dp[row][col] = max(1, healthRequired);   
}

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int n = dungeon.size();
    int m = dungeon[0].size();
    
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int res = solve(0, 0, dungeon, dp, n, m);
    return res;
}



int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<int>> dungeon(n, vector<int>(m));
    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < m; j++)
        {
            cin >> dungeon[i][j];
        }
        
    }
    cout << calculateMinimumHP(dungeon) << endl;
    return 0;
}