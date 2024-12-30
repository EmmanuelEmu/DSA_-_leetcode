#include <bits/stdc++.h>
using namespace std;

int solve(int ind, std::vector<int> &nums, int sum, int lastIndex, vector<vector<int>> &dp) {
    if (ind == nums.size()) {
        return dp[ind-1][lastIndex+1] = sum;
    }
    if (dp[ind][lastIndex+1] != -1) {
        return dp[ind][lastIndex+1];
    }
    int notTake = solve(ind + 1, nums, sum, lastIndex, dp);

    int take = 0;
    if (lastIndex == -1 || abs(nums[ind] - nums[lastIndex]) == 1) {
        take = solve(ind + 1, nums, sum + nums[ind], ind, dp);
    }
    return dp [ind][lastIndex+1] = take + notTake;
}

int sumOfGoodSubsequences(std::vector<int> &nums) {
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
    return solve(0, nums, 0, -1, dp);
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
    cout << sumOfGoodSubsequences(nums) << endl;
    return 0;
}