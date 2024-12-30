#include <bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1), cnt(n, 1);
    int maxi = 1;
    int lastIndex = 0;
    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < i; j++)
        {
            if (nums[i] > nums[j] && dp[i] < 1 + dp[j])
            {
                dp[i] = 1 + dp[j];
                cnt[i] = cnt[j];
            }
            else if (nums[i] > nums[j] && dp[i] == 1 + dp[j])
            {
                cnt[i] += cnt[j];
            }
        }
        if (maxi < dp[i])
        {
            maxi = dp[i];
        }
    }
    int nos = 0;
    for (auto i = 0; i < n; i++)
    {
        if (dp[i] == maxi)
        {
            nos += cnt[i];
        }
    }
    return nos;
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
    cout << findNumberOfLIS(nums) << endl;
    return 0;
}