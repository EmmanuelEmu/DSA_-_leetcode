#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int ind, int prevInd, int k, vector<int> &dp)
{
    if (ind == nums.size())
    {
        return 0;
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    int notTake = solve(nums, ind + 1, ind, k, dp);
    int take = 0;
    if(ind - prevInd <= k && prevInd != -1 || ind == 0){
        take = nums[ind] + solve(nums, ind + 1, ind, k, dp);
    }
    return dp[ind] = max(take, notTake);
}

int constrainedSubsetSum(vector<int> &nums, int k)
{
    vector<int> dp(nums.size(), -1);
    return solve(nums, 0, -1, k, dp);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    while (n--)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cout << constrainedSubsetSum(nums, k) << endl;
    return 0;
}