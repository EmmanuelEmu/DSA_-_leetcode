#include <bits/stdc++.h>
using namespace std;

long long countQuadruplets(vector<int> &nums)
{
    long long count = 0;
    int n = nums.size();
    for (auto i = 0; i < n; i++)
    {
        for (auto j = i + 1; j < n; j++)
        {
            for (auto k = j + 1; k < n; k++)
            {
                for (auto l = k + 1; l < n; l++)
                {
                    if (nums[i] < nums[k] && nums[k] < nums[j] && nums[j] < nums[l])
                    {
                        count++;
                    }
                }
            }
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
    cout << countQuadruplets(nums) << endl;

    return 0;
}