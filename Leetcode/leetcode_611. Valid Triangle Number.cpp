#include <bits/stdc++.h>
using namespace std;

int triangleNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int count = 0;
    int n = nums.size();
    for (auto i = 0; i < n; i++)
    {
        for (auto j = i + 1; j < n; j++)
        {
            int twoSide = nums[i] + nums[j];
            int lb = j+1;
            int ub = n-1;
            while (lb <= ub)
            {
                int mid = lb + (ub - lb) / 2;
                if (nums[mid] < twoSide)
                {
                
                    lb = mid + 1;
                }
                else
                {
                    ub = mid - 1;
                }
            }
            count += ub - j;
        }
    }

    return count;
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
    cout << triangleNumber(nums) << endl;
    return 0;
}