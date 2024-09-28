#include <bits/stdc++.h>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
{
    int lb = 0;
    int ub = nums.size() - 1;
    map<int, vector<int>> mp;
    for (auto i = 0; i < nums.size(); i++)
    {
        mp[nums[i]].push_back(i);
    }
    sort(nums.begin(), nums.end());
    while (lb < ub)
    {
        int idx1 = mp[nums[lb]].back();
        mp[nums[lb]].pop_back();
        int idx2 = mp[nums[ub]].back();
        mp[nums[ub]].pop_back();
        int idxDiff = abs(idx1 - idx2);
        int valDiff = abs(nums[lb] - nums[ub]);
        if (idxDiff <= indexDiff && valDiff <= valueDiff)
        {
            // cout << nums[lb] << " " << nums[ub] << endl;
            // cout << mp[nums[lb]].back << " " << mp[nums[ub]] << endl;
            return true;
        }
        else if (valDiff > valueDiff)
        {
            ub--;
        }
        else
        {
            lb++;
        }
    }
    return false;
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
    int indexDiff, valueDiff;
    cin >> indexDiff >> valueDiff;
    cout << containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff) << endl;

    return 0;
}