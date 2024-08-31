#include <bits/stdc++.h>
using namespace std;

void subSeq(int ind, vector<int> &result, vector<int> &arr, int s, int target, int n, vector<vector<int>> &comb)
{

    if (s > target)
    {
        return;
    }
    if (ind == n)
    {
        if (s == target)
        {
            // sort(result.begin(), result.end());
            comb.push_back(result);
        }
        return;
    }

    result.push_back(arr[ind]);
    s += arr[ind];
    subSeq(ind + 1, result, arr, s, target, n, comb);

    result.pop_back();
    s -= arr[ind];

    while (ind + 1 < n && arr[ind] == arr[ind + 1])
        ind++;
    subSeq(ind + 1, result, arr, s, target, n, comb);
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> comb;
    vector<int> vec;
    subSeq(0, vec, candidates, 0, target, candidates.size(), comb);

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
    int target;
    cin >> target;
    vector<vector<int>> result = combinationSum2(v, target);
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