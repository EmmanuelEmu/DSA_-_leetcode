#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, 1);
    int maxi = 1;
    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        maxi = max(maxi, dp[i]);
    }

    return maxi;
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(nums) << endl;
    return 0;
}