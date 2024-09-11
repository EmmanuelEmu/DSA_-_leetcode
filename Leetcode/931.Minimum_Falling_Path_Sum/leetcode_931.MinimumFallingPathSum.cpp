#include <bits/stdc++.h>
using namespace std;

// Using the memoization technique
// But it still gives the time limit exceeded error
// We need to optimize it 


int solve(vector<vector<int>> &matrix, int row, int col, int n, vector<vector<int>> &dp)
{
    if (row == 0)
    {
        return matrix[row][col];
    }
    if (col < 0 || col >= n)
    {
        return 1e9;
    }

    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    int up = matrix[row][col] + solve(matrix, row - 1, col, n, dp);
    int left = col>0 ? matrix[row][col] + solve(matrix, row - 1, col - 1, n, dp) : 1e9;
    int right = col<n-1 ? matrix[row][col] + solve(matrix, row - 1, col + 1, n, dp) : 1e9;
    return dp[row][col] = min({up, left, right});
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int minSum = INT_MAX;
    int lastRoW = matrix.size();
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
    for (auto j = 0; j < lastRoW; j++)
    {
        int sum = solve(matrix, lastRoW - 1, j, lastRoW, dp);
        minSum = min(minSum, sum);
        // dp.clear();
        // dp.resize(matrix.size(), vector<int>(matrix[0].size(), -1));
    }

    return minSum;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << minFallingPathSum(matrix) << endl;
    return 0;
}