#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &nums, int ind, int sum, vector<vector<int>> &dp, vector<vector<bool>> &used, int target)
{
    // Base cases
    if (sum == 0)
    {
        return true;
    }
    if (sum < 0 || ind < 0)
    {
        return false;
    }
    if (dp[ind][sum] != -1)
    {
        return dp[ind][sum];
    }
    bool notTake = solve(nums, ind - 1, sum, dp, used, target);
    bool take = false;
    if (nums[ind] <= sum && used[nums[ind]][ind] == false)
    {
        used[nums[ind]][ind] = true;
        take = solve(nums, ind - 1, sum - nums[ind], dp, used, target);
        if (ind>0)
        {
            used[nums[ind]][ind] = false;
        }
    }

    return dp[ind][sum] = notTake || take;
}

bool canPartitionKSubsets(vector<int> &nums, int k)
{
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    cout << sum << endl;
    if (sum % k != 0)
    {
        return false;
    }

    int target = sum / k;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    int maxElement = *max_element(nums.begin(), nums.end());
    vector<vector<bool>> used(maxElement + 1, vector<bool>(n, false));
    int count = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (solve(nums, i, target, dp, used, target))
        {
            count++;
        }
        if (count == k)
        {
            return true;
        }
    }
    return false;
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
    bool result = canPartitionKSubsets(nums, k);
    cout << result << endl;
    return 0;
}