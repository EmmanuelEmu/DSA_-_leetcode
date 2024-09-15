#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> &nums)
{
    int totalSum = 0;
    int leftSum = 0;
    for (auto it : nums)
    {
        totalSum += it;
    }

    for (auto i = 0; i < nums.size(); i++)
    {
        if (totalSum - nums[i] -leftSum == leftSum)
        {
            return i;
        }
        leftSum += nums[i];
    }

    return -1;
}

int main()
{
    int n;
    vector<int> arr;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    int result = pivotIndex(arr);
    cout << result << endl;
    return 0;
}