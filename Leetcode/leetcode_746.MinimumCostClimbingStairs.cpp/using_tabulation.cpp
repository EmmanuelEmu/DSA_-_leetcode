#include <bits/stdc++.h>
using namespace std;

// int solve(vector<int> &cost, int n, vector<int> dp, int index){
//     if (index == n)
//     {
//         return cost[n];
//     }
//     if (index > n)
//     {
//         return 0;
//     }
//     if (dp[index] != -1)
//     {
//         return dp[index];
//     }

//     int oneStep = cost[index] + solve(cost, n, dp, index+1);
//     int twoStep = cost[index] + solve(cost, n, dp, index+2);

//     return dp[index] = min(oneStep, twoStep);
// }

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(cost.size(), -1);
    dp[n-1] = cost[n-1];
    dp[n-2] = cost[n-2];
    for (auto i = n-3; i >=0 ; i--)
    {
        int oneStep = cost[i] + dp[i+1];
        int twoStep = cost[i] + dp[i+2];
        dp[i] = min(oneStep, twoStep);
    }
    return min(dp[0], dp[1]);
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
    int result = minCostClimbingStairs(arr);
    cout << result << endl;
    return 0;
}