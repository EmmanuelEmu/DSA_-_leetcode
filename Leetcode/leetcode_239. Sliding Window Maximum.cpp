#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> res;
    priority_queue<pair<int, int>> pq;

    for (int r = 0; r < n; r++)
    {
        pq.push({nums[r], r});
        if (r >= k - 1)
        {
            while (!pq.empty() && pq.top().second < r - k + 1)
            {
                pq.pop();
            }
            res.push_back(pq.top().first);
        }
    }
    return res;
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
    vector<int> res = maxSlidingWindow(nums, k);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}