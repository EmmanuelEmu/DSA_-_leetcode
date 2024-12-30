#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int goal)
{
    int n = nums.size();
    int l = 0, r = 0;
    int count = 0;
    map<int, int> mp;

    while (r < n)
    {
        mp[nums[r]]++;
        while (mp.size() > goal)
        {
            mp[nums[l]]--;
            if (mp[nums[l]] == 0)
            {
                mp.erase(nums[l]);
            }
            l++;
        }
        count += (r - l + 1);
        r++;
    }

    return count;
}

int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return solve(nums, k) - solve(nums, k - 1);
}

int main()
{

    return 0;
}