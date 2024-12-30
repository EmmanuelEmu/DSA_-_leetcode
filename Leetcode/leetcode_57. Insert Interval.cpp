#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int n = intervals.size();
    vector<vector<int>> res;
    int i = 0;
    while (i < n && intervals[i][1] < newInterval[0])
    {
        res.push_back(intervals[i]);
        i++;
    }
    while (i < n && intervals[i][0] <= newInterval[1])
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    res.push_back(newInterval);
    while (i < n)
    {
        res.push_back(intervals[i]);
        i++;
    }
    return res;
}

int main()
{
    int n;
    vector<vector<int>> intervals;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        intervals.push_back({a, b});
    }
    vector<int> newInterval;
    int a, b;
    cin >> a >> b;
    newInterval.push_back(a);
    newInterval.push_back(b);
    vector<vector<int>> res = insert(intervals, newInterval);
    for (auto it : res)
    {
        cout << it[0] << " " << it[1] << endl;
    }
    cout << endl;
    return 0;
}