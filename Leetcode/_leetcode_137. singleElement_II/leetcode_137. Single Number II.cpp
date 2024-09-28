#include <bits/stdc++.h>
using namespace std;

// using the group method
int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (auto i = 1; i < n; i = i + 3)
    {
        if (nums[i] != nums[i - 1])
        {
            return nums[i - 1];
        }
    }
    return nums[n - 1];
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
    cout << singleNumber(nums) << endl;
    return 0;
}