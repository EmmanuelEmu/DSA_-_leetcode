#include <bits/stdc++.h>
using namespace std;


// This is the advance version of the unique paths problem
// I've solve is using Tabulation process to optimize the recurrance
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1)
    {
        return 0;
    }
    if (obstacleGrid[m - 1][n - 1] == 1)
    {
        return 0;
    }
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 1; i < m; i++)
    {
        if (obstacleGrid[i][0] == 1)
        {
            dp[i][0] = 0;
        }
        else
        {
            dp[i][0] = dp[i - 1][0]; 
        }
        
    }

    for (int j = 1; j < n; j++)
    {
        if (obstacleGrid[0][j] == 1)
        {
            dp[0][j] = 0;
        }
        else
        {
            dp[0][j] = dp[0][j - 1];
        }
        
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (obstacleGrid[i][j]== 1)
            {
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp;
    for (auto i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            dp[i].push_back(a);
        }
    }

    cout << uniquePathsWithObstacles(dp) << endl;
    return 0;
}
