#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int ones = 0, twos = 0;
    for(auto it: nums){
        ones = (ones ^ it) & ~twos;
        twos = (twos ^ it) & ~ones;
    }
    return ones;
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