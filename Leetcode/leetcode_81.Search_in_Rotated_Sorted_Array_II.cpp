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

bool search(vector<int> &nums, int target)
{
    if (nums.size() == 1)
    {
        if (nums[0] == target)
        {
            return true;
        } else{
            return false;
        }
        
    }
    

    int tipIdx = tipIndex(nums);
    cout << tipIdx << endl;
    int lb, ub;

    if (tipIdx == -1)
    {
        lb = 0;
        ub = nums.size()-1;
    }
    
    else if (nums[tipIdx - 1] >= target && nums[0] <=target)
    {
        lb = 0;
        ub = tipIdx - 1;
    }
    else
    {
        lb = tipIdx;
        ub = nums.size() - 1;
    }
    cout << lb << " " << ub << endl;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (nums[mid] == target)
        {
            return true;
        }
        else if (nums[mid] > target)
        {
            ub = mid - 1;
        }
        else
        {
            lb = mid + 1;
        }
    }
    return false;
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
    int target;
    cin >> target;
    int res = search(v, target);
    cout << res << endl;
    return 0;
}