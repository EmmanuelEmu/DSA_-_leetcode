#include <bits/stdc++.h>
using namespace std;

int thirdMax(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    auto it = unique(nums.begin(), nums.end());
    nums.resize(distance(nums.begin(), it));
    if (nums.size() < 3)
    {
        return nums[nums.size() - 1];
    }
    return nums[nums.size() - 3];
}

int main()
{

    return 0;
}