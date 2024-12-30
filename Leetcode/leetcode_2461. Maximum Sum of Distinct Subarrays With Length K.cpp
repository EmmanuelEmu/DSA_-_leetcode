#include <bits/stdc++.h>
using namespace std;

long long maximumSubarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    long long sum = 0, maxSum = 0;
    map<int, int> mp;
    int l = 0, r = 0;

    while (r < n)
    {
        mp[nums[r]]++;
        sum += nums[r];

        while (mp[nums[r]] > 1)
        {
            mp[nums[l]]--;
            sum -= nums[l];
            if (mp[nums[l]] == 0)
            {
                mp.erase(nums[l]);
            }
            l++;
        }
        if (r - l + 1 == k)
        {
            maxSum = max(maxSum, sum);
            mp[nums[l]]--;
            sum -= nums[l];
            if (mp[nums[l]] == 0)
            {
                mp.erase(nums[l]);
            }
            l++;
        }
        r++;
    }

    return maxSum;
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
    cout << maximumSubarraySum(nums, k) << endl;
    return 0;
}