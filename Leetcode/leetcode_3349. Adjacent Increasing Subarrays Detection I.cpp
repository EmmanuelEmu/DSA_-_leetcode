#include <bits/stdc++.h>
using namespace std;

bool hasIncreasingSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    for (int i = 0; i <= n - 2 * k; i++)
    {
        bool flag = true;

        for (int j = i; j < i + k - 1; j++)
        {
            if (nums[j] >= nums[j + 1])
            {
                flag = false;
                break;
            }
        }

        if (!flag)
            continue;
        for (int j = i + k; j < i + 2 * k - 1; j++)
        {
            if (nums[j] >= nums[j + 1])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            return true;
    }

    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    while (n--)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cout << hasIncreasingSubarrays(nums, k) << endl;
    return 0;
}