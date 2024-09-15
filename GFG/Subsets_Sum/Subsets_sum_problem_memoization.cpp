#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> arr, int sum, int ind, vector<vector<bool>> &dp){
    if(arr[0] == sum){
        return true;
    }
    if (sum == 0)
    {
        return true;
    }
    if (ind == 0)
    {
        return false;
    }

    if (dp[ind][sum] != false)
    {
        return dp[ind][sum];
    }

    bool notTake = solve(arr, sum, ind-1, dp);
    bool take = false;
    if (arr[ind] <= sum)
    {
        take = solve(arr, sum-arr[ind], ind-1, dp);
    }
    return dp[ind][sum] =  notTake || take;
}

bool isSubsetSum(vector<int> arr, int sum)
{
    vector<vector<bool>> dp(arr.size(), vector<bool>(sum+1, false));
    return solve(arr, sum, arr.size()-1, dp);
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