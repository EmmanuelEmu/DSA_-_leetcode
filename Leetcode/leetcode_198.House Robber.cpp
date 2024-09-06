#include <bits/stdc++.h>
using namespace std;

int maxNum(vector<int> &nums, int ind, vector<int> &dp){
    if (ind == 0)
    {
        return nums[0];
    }
    if(ind == -1){
        return 0;
    }
    if (dp[ind]!= -1)
    {
        return dp[ind];
    }
    
    int pick = nums[ind] + maxNum(nums, ind-2, dp);
    int notPick = maxNum(nums, ind-1, dp);
    return dp[ind] = max(pick, notPick);
}

int rob(vector<int> &nums)
{
    vector<int> dp(nums.size(), -1);
    return maxNum(nums, nums.size()-1, dp);
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