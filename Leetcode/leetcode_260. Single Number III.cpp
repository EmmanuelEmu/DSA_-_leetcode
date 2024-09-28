#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int> &nums)
{
    long long xorr = 0;
    for (auto it : nums)
    {
        xorr ^= it;
    }
    int rightMost = (xorr & xorr - 1)^xorr;
    int leftBucket = 0, rightBucket = 0;
    for (auto it : nums)
    {
        if (it & rightMost)
        {
            leftBucket ^= it;
        }
        else
        {
            rightBucket ^= it;
        }
    }
    return {leftBucket, rightBucket};
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
    vector<int> res = singleNumber(nums);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}