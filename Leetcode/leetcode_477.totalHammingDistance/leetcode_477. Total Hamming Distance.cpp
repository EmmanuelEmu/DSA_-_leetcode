#include <bits/stdc++.h>
using namespace std;

int hammingDistance(int x, int y)
{
    int n = x ^ y;
    int count = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        count++;
    }

    return count;
}

int totalHammingDistance(vector<int> &nums)
{
    int count = 0;
    for (auto i = 0; i < nums.size(); i++)
    {
        for (auto j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                continue;
            }
            else
            {
                count += hammingDistance(nums[i], nums[j]);
            }
        }
    }
    return count;
}

int main()
{

    return 0;
}