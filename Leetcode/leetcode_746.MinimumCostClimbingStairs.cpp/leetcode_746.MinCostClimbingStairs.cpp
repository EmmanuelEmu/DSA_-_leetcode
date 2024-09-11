#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &cost, int n, vector<int> dp, int index){
    if (index == n)
    {
        return cost[n];
    }
    if (index > n)
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }

    int oneStep = cost[index] + solve(cost, n, dp, index+1);
    int twoStep = cost[index] + solve(cost, n, dp, index+2);

    return dp[index] = min(oneStep, twoStep);
}

int minCostClimbingStairs(vector<int> &cost)
{
    vector<int> dp(cost.size(), -1);
    return min(solve(cost, cost.size()-1, dp, 0), solve(cost, cost.size()-1, dp, 1));
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