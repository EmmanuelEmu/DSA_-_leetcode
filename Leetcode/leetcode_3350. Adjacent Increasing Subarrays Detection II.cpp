#include <bits/stdc++.h>
using namespace std;

int maxIncreasingSubarrays(vector<int> &nums)
{
    int n = nums.size();
    vector<int> pre(n, 1);
    for (auto i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1] + 1)
        {
            pre[i] = pre[i - 1] + 1;
        }
    }

    for (auto i = 0; i < pre.size(); i++)
    {
        cout << pre[i] << " ";
    }
    cout << endl;
    int maxLen = 1;
    int maxCount = 1;
    for (auto i = 0; i < pre.size(); i++)
    {
        if (pre[i] > maxCount)
        {
            auto it = std::find(nums.begin() + i + 1, nums.end(), nums[i]);
            if (it != nums.end())
            {
                int dis = distance(nums.begin() + i, it);
                maxLen = max(maxLen, dis+1);
                maxCount = pre[i];
            }
        }
    }
    return maxLen;
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
    cout << maxIncreasingSubarrays(nums) << endl;
    return 0;
}