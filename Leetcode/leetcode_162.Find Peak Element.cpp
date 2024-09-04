#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return 0;
    }
    if (nums[0] > nums[1])
    {
        return 0;
    }
    if (nums[n - 1] > nums[n - 2])
    {
        return n - 1;
    }

    int lb = 1;
    int ub = n - 2;

    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if ((nums[mid - 1] < nums[mid]) && (nums[mid] > nums[mid + 1]))
        {
            return mid;
        }
        else if (nums[mid] < nums[mid + 1])
        {
            lb = mid + 1;
        }
        else
        {
            ub = mid - 1;
        }
    }

    return -1;
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
    int res = findPeakElement(v);
    cout << res << endl;
    return 0;
}
