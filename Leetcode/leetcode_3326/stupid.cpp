#include <bits/stdc++.h>
using namespace std;

int greatestProperDivisor(int n1, int n2)
{
    for (int i = 2; i <= n1; i++)
    {
        if (n2 % i == 0)
            return i;
    }
    return -1;
}

int minOperations(vector<int> &nums)
{
    int n = nums.size();
    int minOp = 0;
    for (auto i = n - 1; i >= 0; i--)
    {
        if (nums[i] < nums[i - 1])
        {
            nums[i - 1] /= greatestProperDivisor(nums[i], nums[i - 1]);
            if (nums[i - 1] == -1)
            {
                return -1;
            }
            minOp++;
        }
    }

    return minOp;
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
    cout << minOperations(nums) << endl;
    return 0;
}