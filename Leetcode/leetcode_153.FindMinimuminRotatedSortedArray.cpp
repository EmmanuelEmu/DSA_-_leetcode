#include <bits/stdc++.h>
using namespace std;

int tipIndex(vector<int> &nums)
{
    for (auto i = 1; i < nums.size(); i++)
    {
        if (nums[i] < nums[i - 1])
        {
            return i;
        }
    }
    return -1;
}

int findMin(vector<int>& nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }
    

    int tipIdx = tipIndex(nums);
    // cout << tipIdx << endl;
    int lb, ub;
    int min;

    if (tipIdx == -1)
    {
        min = nums[0];
    }
    
    else if (nums[0] > nums[tipIdx])
    {
        min = nums[tipIdx];
    }
    else
    {
        min = nums[0];
    }
    // cout << lb << " " << ub << endl;
    // while (lb <= ub)
    // {
    //     int mid = lb + (ub - lb) / 2;
    //     if (nums[mid] == target)
    //     {
    //         return mid;
    //     }
    //     else if (nums[mid] > target)
    //     {
    //         ub = mid - 1;
    //     }
    //     else
    //     {
    //         lb = mid + 1;
    //     }
    // }
    // return -1;

    return min;
}

int main()
{
    int n;
    vector<int> v;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int res = findMin(v);
    cout << res << endl;
    return 0;
}