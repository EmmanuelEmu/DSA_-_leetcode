#include <bits/stdc++.h>
using namespace std;

int maximumPoints(vector<vector<int>> &arr, int n) {
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // Initialize the base case (i = 0)
    dp[0][0] = max(arr[0][1], arr[0][2]);
    dp[0][1] = max(arr[0][0], arr[0][2]);
    dp[0][2] = max(arr[0][0], arr[0][1]);
    dp[0][3] = max({arr[0][0], arr[0][1], arr[0][2]});

    // Start the loop from i = 1 (since i = 0 is already handled)
    for (int i = 1; i < n; i++) {
        for (int last = 0; last < 4; last++) {
            int maxi = 0;
            for (int j = 0; j < 3; j++) {
                if (j != last) {
                    maxi = max(maxi, arr[i][j] + dp[i - 1][j]);
                }
            }
            dp[i][last] = maxi;
        }
    }

    return dp[n - 1][3];
}


int main()
{

    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));
    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << maximumPoints(arr, n) << endl;
    return 0;
}