#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int k, int ind, int sum)
{
    if (ind == nums.size())
    {
        return (sum % k == 0) ? 1 : 0;
    }

    // Include current element in the subarray
    sum += nums[ind];
    int pick = solve(nums, k, ind + 1, sum);

    // Exclude current element from the subarray
    sum -= nums[ind];
    int notPick = solve(nums, k, ind + 1, sum);
    
    return pick + notPick;
}

int subarraysDivByK(vector<int> &nums, int k)
{
    return solve(nums, k, 0, 0);
}


int main()
{
    int n, k;
    vector<int> arr;
    cin >> n >> k;
    while (n--)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    int result = subarraysDivByK(arr, k);
    cout << result << endl;
    return 0;
}