#include <bits/stdc++.h>
using namespace std;

int maxNum(vector<int> &nums, int ind, vector<int> &dp, int start)
{
    if (ind < start)
    {
        return 0;
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }

    int pick = nums[ind] + maxNum(nums, ind - 2, dp, start);
    int notPick = maxNum(nums, ind - 1, dp, start);
    return dp[ind] = max(pick, notPick);
}

int rob(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }

    vector<int> dp1(nums.size(), -1);
    int case1 = maxNum(nums, nums.size() - 1, dp1, 1);

    vector<int> dp2(nums.size(), -1);
    int case2 = maxNum(nums, nums.size() - 2, dp2, 0);
    return max(case1, case2);
}
int main()
{

    vector<int> v;
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    cout << rob(v) << endl;
    return 0;
}