#include <bits/stdc++.h>
using namespace std;


// Unsolved

bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
{
    int lb = 0;
    int ub = nums.size() - 1;
    while (lb <= ub)
    {
        int idxDiff = abs(lb - ub);
        int valDiff = abs(nums[lb] - nums[ub]);
        if (idxDiff <= indexDiff && valDiff <= valueDiff)
        {
            return true;
        }
        else if (idxDiff > indexDiff)
        {
            lb++;
        }
        else
        {
            ub--;
        }
    }
    return false;
}

int main()
{

    return 0;
}