#include <bits/stdc++.h>
using namespace std;


int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    for (auto ind = n - 1; ind >= 0; ind--)
    {
        for (auto prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            int not_take = 0 + dp[ind + 1][prev_ind + 1];
            int take = 0;
            if (prev_ind == -1 || nums[ind] > nums[prev_ind])
            {
                take = 1 + dp[ind + 1][ind + 1];
            }
            dp[ind][prev_ind + 1] = max(take, not_take);
        }
    }
    return dp[0][0];
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(nums) << endl;
    return 0;
}