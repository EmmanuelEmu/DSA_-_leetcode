#include <bits/stdc++.h>
using namespace std;

long long minimalKSum(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    long long sum = 0;
    int count = 0;
    long long current = 1;

    for (int num : nums)
    {
        while (current < num && count < k)
        {
            sum += current;
            current++;
            count++;
        }

        if (current == num)
        {
            current++;
        }
        if (count == k)
        {
            return sum;
        }
    }
    while (count < k)
    {
        sum += current;
        current++;
        count++;
    }

    return sum;
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
    cout << minimalKSum(nums, k) << endl;
    return 0;
}