#include <bits/stdc++.h>
using namespace std;

int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end());
    int ans = 1;
    int end = points[0][1];
    for (auto i = 1; i < points.size(); i++)
    {
        if (points[i][0] <= end)
        {
            end = min(end, points[i][1]);
        }
        else
        {
            ans++;
            end = points[i][1];
        }
    }
    return ans;
}

int main()
{

    return 0;
}