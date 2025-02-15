#include <bits/stdc++.h>
using namespace std;

int setBitCount(int n)
{
    int count = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

bool canSortArray(vector<int> &nums)
{

    int n = nums.size();
    for (auto i = 0; i < n; i++)
    {
        for (auto j = i + 1; j < n; j++)
        {
            if (nums[i] <= nums[j])
            {
                continue;
            }
            else
            {
                if (setBitCount(nums[i]) == setBitCount(nums[j]))
                {
                    swap(nums[i], nums[j]);
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << (canSortArray(nums) ? "true" : "false") << endl;
    return 0;
}
