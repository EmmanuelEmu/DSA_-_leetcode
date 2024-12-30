#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<vector<int>> &events, int idx)
{
    int lb = idx + 1;
    int ub = events.size() - 1;
    int nextInd = -1;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (events[mid][0] > events[idx][1])
        {
            nextInd = mid;
            ub = mid - 1;
        }
        else
        {
            lb = mid + 1;
        }
    }
    return nextInd;
}

int solve(const vector<vector<int>> &events, int k, int idx, vector<vector<int>> &dp, const vector<int> &nextIdx)
{
    if (k == 2 || idx >= events.size())
    {
        return 0;
    }
    if (dp[idx][k] != -1)
    {
        return dp[idx][k];
    }
    int take = events[idx][2] + solve(events, k + 1, nextIdx[idx], dp, nextIdx);
    int notTake = solve(events, k, idx + 1, dp, nextIdx);
    return dp[idx][k] = max(take, notTake);
}

int maxTwoEvents(vector<vector<int>> &events)
{
    int n = events.size();
    sort(events.begin(), events.end());

    // Precompute next indices for all events
    vector<int> nextIdx(n, -1);
    for (int i = 0; i < n; ++i)
    {
        nextIdx[i] = upperBound(events, i);
    }

    // Initialize DP table
    vector<vector<int>> dp(n, vector<int>(3, -1));
    return solve(events, 0, 0, dp, nextIdx);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> events;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        events.push_back({a, b, c});
    }
    cout << maxTwoEvents(events) << endl;
    return 0;
}