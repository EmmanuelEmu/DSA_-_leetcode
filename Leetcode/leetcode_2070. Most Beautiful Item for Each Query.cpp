#include <bits/stdc++.h>
using namespace std;

vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
{

    sort(items.begin(), items.end());

    //Cumulative maximum beauty finding
    for (int i = 1; i < items.size(); i++)
    {
        items[i][1] = max(items[i][1], items[i - 1][1]);
    }

    vector<int> res;
    for (int q : queries)
    {
        int lb = 0, ub = items.size() - 1, maxi = 0;
        while (lb <= ub)
        {
            int mid = lb + (ub - lb) / 2;
            if (items[mid][0] <= q)
            {
                maxi = items[mid][1];
                lb = mid + 1;
            }
            else
            {
                ub = mid - 1;
            }
        }

        res.push_back(maxi);
    }
    return res;
}

int main()
{
    vector<vector<int>> items;
    vector<int> queries;
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        items.push_back({a, b});
    }
    int m;
    cin >> m;
    while (m--)
    {
        int a;
        cin >> a;
        queries.push_back(a);
    }
    vector<int> res = maximumBeauty(items, queries);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}