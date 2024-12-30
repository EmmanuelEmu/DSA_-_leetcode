#include <bits/stdc++.h>
using namespace std;

int setBitCount(int n)
{
    int count = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

vector<int> sortByBits(vector<int> &arr)
{
    int n = arr.size();
    map<int, vector<int>> mp;
    for (auto i = 0; i < n; i++)
    {
        mp[setBitCount(arr[i])].push_back(arr[i]);
    }

    vector<int> res;
    for(auto it: mp){
        sort(it.second.begin(), it.second.end());
        res.insert(res.end(), it.second.begin(), it.second.end());
    }
    return res;
}

int main()
{

    return 0;
}