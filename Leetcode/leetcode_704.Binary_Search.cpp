#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int lb = 0;
    int ub = nums.size()-1;

    while (lb <ub)
    {
        int mid = (lb+ub)/2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            ub = mid-1;
        }
        else
        {
            lb = mid+1;
        }
    }
    return -1;
}

int main()
{
    vector<int> v;
    int n, target;

    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    cin >> target;
    int res = search(v, target);
    cout << res << endl;

    return 0;
}