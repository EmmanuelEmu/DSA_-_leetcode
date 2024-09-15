#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int> arr, int sum)
{
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
    for (auto i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= sum)
    {
        dp[0][arr[0]] = true;
    }
    for (auto i = 1; i < n; i++)
    {
        for (auto j = 1; j <= sum; j++)
        {
            bool notTake = dp[i - 1][j];
            bool take = false;
            if (arr[i] <= j)
            {
                take = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = notTake || take;
        }
    }

    return dp[n - 1][sum];
}

int main()
{

    int n;
    vector<int> arr;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    int sum;
    cin >> sum;
    bool result = isSubsetSum(arr, sum);
    cout << result << endl;
    return 0;
}