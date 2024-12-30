#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &nums, int mid, int maxOperations)
{
    int totalOperations = 0;
    for (auto num : nums)
    {
        int maxOp = ceil((double)num / mid) - 1;
        totalOperations += maxOp;
        if (totalOperations > maxOperations)
        {
            return false;
        }
    }
    return true;
}

int minimumSize(vector<int> &nums, int maxOperations)
{
    int n = nums.size();
    int ans = -1;
    int l = 1, r = *max_element(nums.begin(), nums.end());
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (isPossible(nums, mid, maxOperations))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n, maxOperations;
    cin >> n >> maxOperations;
    vector<int> nums;
    while (n--)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cout << minimumSize(nums, maxOperations) << endl;
    return 0;
}