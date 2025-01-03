#include <bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    int ans = 0;
    int end = intervals[0][1];
    for (auto i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] < end)
        {
            ans++;
            end = min(end, intervals[i][1]);
        }
        else
        {
            end = intervals[i][1];
        }
    }
    return ans;
}

int main()
{

    return 0;
}