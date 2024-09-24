#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    map<int, int> preSumMap;
    int sum = 0;
    int res = 0;
    preSumMap[0] = 1;
    for (auto i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        int rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            res += preSumMap[rem];
        }
        preSumMap[sum]++;
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
    int k;
    cin >> k;
    cout << subarraySum(nums, k) << endl;
    return 0;
}