#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int target, int ind, vector<vector<int>> &dp)
{
    if (ind == nums.size())
    {
        return target == 0 ? 1 : 0;
    }
    if (dp[ind][target] != -1)
    {
        return dp[ind][target];
    }
    int include = 0;
    if (target >= nums[ind])
    {
        include = solve(nums, target - nums[ind], ind + 1, dp);
    }
    int exclude = solve(nums, target, ind + 1, dp);
    return dp[ind][target] = include + exclude;
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int sum = 0;
    for (int num : nums)
    {
        sum += num;
    }

    // Early exit condition: If the sum + target is odd or sum < abs(target), return 0.
    if (sum < abs(target) || (sum + target) % 2 != 0)
    {
        return 0;
    }

    // Convert the problem to a subset sum problem
    int subsetSum = (sum + target) / 2;

    // DP initialization
    vector<vector<int>> dp(nums.size(), vector<int>(subsetSum + 1, -1));

    return solve(nums, subsetSum, 0, dp);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    while (n--)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    int target;
    cin >> target;
    cout << findTargetSumWays(nums, target) << endl;
    return 0;
}