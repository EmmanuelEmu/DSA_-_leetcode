#include <bits/stdc++.h>
using namespace std;

int greatestProperDivisor(int n)
{
    if (n == 1)
    {
        return -1; // 1 has no proper divisors
    }
    // Start checking from n / 2 and work downwards
    for (int i = n / 2; i > 0; --i)
    {
        if (n % i == 0)
        {
            return i; // Found the greatest proper divisor
        }
    }
    return -1; // This should never be reached, as every number has 1 as a proper divisor
}

int minOperations(vector<int> &nums)
{
    int minOperations = 0;
    int n = nums.size();
    int minIdx = -1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] < nums[i - 1])
        {
            minIdx = i;
        }
    }
    if (minIdx == -1)
    {
        return 0;
    }
    else
    {
        for (auto j = minIdx - 1; j >= 0; j--)
        {
            if (nums[j] < nums[j + 1])
                break;
            int div = greatestProperDivisor(nums[j]);
            if (div == -1)
            {
                return -1;
            }
            else if (nums[j] / div <= nums[j + 1])
            {
                nums[j] /= div;
                minOperations++;
            }
            else
            {
                return -1;
            }
        }
    }

    return minOperations;
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