#include <bits/stdc++.h>
using namespace std;

// int shortestSubarray(vector<int> &nums, int k)
// {
//     int n = nums.size();
//     int l = 0, r = 0;
//     int sum = 0;
//     int minLen = INT_MAX;
//     while (r < n)
//     {
//         sum += nums[r];
//         while (sum >= k)
//         {
//             minLen = min(minLen, r - l + 1);
//             sum -= nums[l];
//             l++;
//         }
//         r++;
//     }
//     return minLen == INT_MAX ? -1 : minLen;
// }

int shortestSubarray(vector<int> &nums, int k)
{
    int n = nums.size();
    deque<int> dq;                        
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    int minLen = INT_MAX;

    for (int i = 0; i <= n; ++i)
    {
        while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k)
        {
            minLen = min(minLen, i - dq.front());
            dq.pop_front();
        }
        while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    return minLen == INT_MAX ? -1 : minLen;
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
    cout << shortestSubarray(nums, k) << endl;
    return 0;
}