#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int n = nums.size();
    int l = 0, r = 0;
    int sum = 0;
    int minLen = INT_MAX;
    while (r < n)
    {
        sum += nums[r];
        while (sum >= target)
        {
            minLen = min(minLen, r - l + 1);
            sum -= nums[l];
            l++;
        }
        r++;
    }
    if (minLen == INT_MAX)
    {
        return 0;
    }
    return minLen;
}

int main()
{

    return 0;
}