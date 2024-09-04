#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &nums, int target)
{
    int lb = 0;
    int ub = nums.size() - 1;
    int ans = nums.size();
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (nums[mid] >= target)
        {
            ans = mid;
            ub = mid - 1;
        }
        else
        {
            lb = mid + 1;
        }
    }
    return ans;
}

int upperBound(vector<int> &nums, int target)
{
    int lb = 0;
    int ub = nums.size() - 1;
    int ans = nums.size();
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (nums[mid] > target)
        {
            ans = mid;
            ub = mid - 1;
        }
        else
        {
            lb = mid + 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int lb = lowerBound(nums, target);
    if (lb == nums.size() || nums[lb]!=target)
    {
        return {-1,-1};
    }
    return {lb, upperBound(nums, target)-1};
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
    vector<int> res = searchRange(v, target);
    for (auto it: res)
    {
        cout << it << " ";
    }
    return 0;
}