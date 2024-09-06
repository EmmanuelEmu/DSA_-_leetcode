#include <bits/stdc++.h>
using namespace std;

int paths(int m, int n, int row, int col, vector<vector<int>> dp)
{
    if (row == m && col == n)
    {
        return 1;
    }
    if (row > m || col > n)
    {
        return 0;
    }

    if (dp[row][col] != -1)
    {
        return 0;
    }

    return dp[row][col] = paths(m, n, row + 1, col, dp) + paths(m, n, row, col + 1, dp);
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return paths(m - 1, n - 1, 0, 0, dp);
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << uniquePaths(m, n) << endl;
    return 0;
}