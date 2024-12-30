#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int goal)
{
    int n = nums.size();
    int l = 0, r = 0;
    int count = 0;
    int sum = 0;
    while (r < n)
    {
        sum += nums[r];
        while (sum > goal)
        {
            sum -= nums[l];
            l++;
        }
        if (sum <= goal)
        {
            count += r - l + 1;
        }
        r++;
    }

    return count;
}

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    return solve(nums, goal)- solve(nums, goal-1);
}

int main()
{

    return 0;
}