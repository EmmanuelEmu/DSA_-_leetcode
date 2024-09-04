#include <bits/stdc++.h>
using namespace std;

void subSeq(int ind, vector<int> &result, vector<int> &arr, int n, vector<vector<int>> &comb)
{

    if (ind == n)
    {
        comb.push_back(result);
        return;
    }

    result.push_back(arr[ind]);
    subSeq(ind + 1, result, arr, n, comb);

    while (ind + 1 < n && arr[ind] == arr[ind + 1])
        ind++;
    result.pop_back();
    subSeq(ind + 1, result, arr, n, comb);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> comb;
    comb.push_back(vector<int>());
    vector<int> vec;
    subSeq(0, vec, nums, nums.size(), comb);

    for (auto &vec : comb)
    {
        sort(vec.begin(), vec.end());
    }
    std::sort(comb.begin(), comb.end());
    auto it = std::unique(comb.begin(), comb.end());
    comb.resize(std::distance(comb.begin(), it));

    return comb;
}

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    vector<vector<int>> result = subsets(v);
    for (auto vec : result)
    {
        for (auto num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}