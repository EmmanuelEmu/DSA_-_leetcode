#include <bits/stdc++.h>
using namespace std;

int minimumDifference(vector<int> &nums)
{
    int sum = 0;
    int minVal = *min_element(nums.begin(), nums.end()); // Find the minimum value in the array

    // If there are negative values, shift all elements by -minVal to make them non-negative
    if (minVal < 0)
    {
        for (auto &num : nums)
        {
            num += abs(minVal); // Shift each element to make them non-negative
        }
    }
    for (auto it : nums)
    {
        sum += it;
    }
    int n = nums.size();
    int target = sum / 2;
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
    for (auto i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (nums[0] <= sum)
    {
        dp[0][nums[0]] = true;
    }
    for (auto i = 1; i < n; i++)
    {
        for (auto j = 1; j <= target; j++)
        {
            bool notTake = dp[i - 1][j];
            bool take = false;
            if (nums[i] <= j)
            {
                take = dp[i - 1][j - nums[i]];
            }
            dp[i][j] = notTake || take;
        }
    }
    int s1 = 0;
    for (int j = target; j >= 0; j--)
    {
        if (dp[n - 1][j])
        {
            s1 = j;
            break;
        }
    }
    int s2 = sum - s1;
    return abs(s1 - s2);
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
    cout << minimumDifference(nums) << endl;
    return 0;
}