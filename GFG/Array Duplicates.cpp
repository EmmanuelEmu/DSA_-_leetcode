#include <bits/stdc++.h>
using namespace std;

vector<int> duplicates(vector<int> arr)
{
    map<int, int> mp;
    for (auto it : arr)
    {
        mp[it]++;
    }

    vector<int> res;
    for (auto it : mp)
    {
        if (it.second > 1)
        {
            res.push_back(it.first);
        }
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    while (n--)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    vector<int> res = duplicates(arr);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}