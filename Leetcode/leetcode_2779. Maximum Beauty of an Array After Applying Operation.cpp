#include <bits/stdc++.h>
using namespace std;

int maximumBeauty(vector<int> &nums, int k)
{
    vector<pair<int, int>> range;
    int n = nums.size();
    for (auto it : nums)
    {
        int lower = it - k;
        int upper = it + k;
        range.push_back({lower, upper});
    }
    sort(range.begin(), range.end());
    int lb = 0, rb = 0;
    int count = 0;
    int totalBeauty = INT_MIN;
    while (rb < range.size())
    {
        if (range[rb].first <= range[lb].second)
        {
            count++;
        }
        if (range[rb].first > range[lb].second)
        {
            while (range[lb].second < range[rb].first)
            {
                count--;
                lb++;
            }
        }
        int len = rb - lb + 1;
        totalBeauty = max(len, totalBeauty);
        rb++;
    }
    return totalBeauty;
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
    cout << maximumBeauty(nums, k) << endl;
    return 0;
}
