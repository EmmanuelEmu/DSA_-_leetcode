#include <bits/stdc++.h>
using namespace std;

int sol(vector<vector<int>> &triangle, int i, int j, int n, vector<vector<int>> &dp){
    if (i==n-1)
    {
        return triangle[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int down = triangle[i][j] + sol(triangle, i+1, j, n, dp);
    int diag = triangle[i][j] + sol(triangle, i+1, j+1, n, dp);
    return dp[i][j] = min(down, diag);
    
}
// Using memoization
int minimumTotal(vector<vector<int>> &triangle)
{
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
    return sol(triangle, 0, 0, triangle.size(), dp);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> triangle;
    for (auto i = 0; i < n; i++)
    {
        vector<int> temp;
        for (auto j = 0; j <= i; j++)
        {
            int a;
            cin >> a;
            temp.push_back(a);
        }
        triangle.push_back(temp);
    }

    cout << minimumTotal(triangle) << endl;
    return 0;
}