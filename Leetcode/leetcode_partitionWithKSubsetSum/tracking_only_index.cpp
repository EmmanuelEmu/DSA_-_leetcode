#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int ind, int sum, vector<vector<int>> &dp, vector<vector<bool>> &used)
{
    if (sum == 0)
    {
        return 1;
    }
    if (ind == 0)
    {
        if (sum == nums[0] && used[sum][ind] == false)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (dp[ind][sum] != -1)
    {
        return dp[ind][sum];
    }

    int notTake = solve(nums, ind - 1, sum, dp, used);
    int take = 0;
    if (nums[ind] <= sum && used[sum][ind] == false && sum!=nums[ind+1])
    {
        used[sum][ind] = true;
        take = solve(nums, ind - 1, sum - nums[ind], dp, used);
        // used[sum][ind] = false;
    }
    return dp[ind][sum] = notTake + take;
}

bool canPartitionKSubsets(vector<int> &nums, int k)
{

    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0)
    {
        return false;
    }
    int target = sum / k;
    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
    vector<vector<bool>> used(target + 1, vector<bool>(nums.size(), false));
    // cout << sum / 2 << endl;
    int res = solve(nums, nums.size() - 1, target, dp, used);
    cout << res << endl;
    if (res >= k)
    {
        return true;
    }
    return false;
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
    int k;
    cin >> k;
    bool result = canPartitionKSubsets(nums, k);
    cout << result << endl;
    return 0;
}