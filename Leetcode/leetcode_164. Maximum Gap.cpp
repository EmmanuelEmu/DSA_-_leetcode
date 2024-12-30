#include <bits/stdc++.h>
using namespace std;

int maximumGap(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int maxGap = 0;
    for (auto i = 0; i < nums.size()-1; i++)
    {
        maxGap = max(maxGap, nums[i+1]-nums[i]);
    }
    return maxGap;
}

int main()
{

    return 0;
}