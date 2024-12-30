#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int prev_ind, vector<int> &nums, vector<vector<int>> &dp)
{
    if (ind == nums.size())
    {
        return 0;
    }
    if (dp[ind][prev_ind + 1] != -1)
    {
        return dp[ind][prev_ind + 1];
    }
    int not_take = 0 + solve(ind + 1, prev_ind, nums, dp);
    int take = 0;
    if (prev_ind == -1 || nums[ind] > nums[prev_ind])
    {
        take = 1 + solve(ind + 1, ind, nums, dp);
    }
    return dp[ind][prev_ind + 1] = max(take, not_take);
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(0, -1, nums, dp);
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(nums) << endl;
    return 0;
}