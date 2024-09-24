#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int prefix = 1;
    int suffix = 1;
    int res = INT_MIN;
    for (auto i = 0; i < nums.size(); i++)
    {
        if (prefix == 0)
        {
            prefix = 1;
        }
        if (suffix == 0)
        {
            suffix = 1;
        }
        prefix *= nums[i];
        suffix *= nums[nums.size() - i - 1];
        res = max(res, max(prefix, suffix));
    }
    return res;
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
    cout << maxProduct(nums) << endl;
    return 0;
}