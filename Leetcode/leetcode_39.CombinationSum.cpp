#include <bits/stdc++.h>
using namespace std;

void subSeq(int ind, vector<int> &res, vector<int> &arr, int s, int sum, int n, vector<vector<int>> &comb)
{
    if (s == sum)
    {
        comb.push_back(res);
        return;
    }

    if (ind == n || s > sum)
    {
        return;
    }

    res.push_back(arr[ind]);
    s += arr[ind];
    subSeq(ind, res, arr, s, sum, n, comb);

    s -= arr[ind];
    res.pop_back();
    subSeq(ind + 1, res, arr, s, sum, n, comb);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> comb;
    vector<int> vec;
    subSeq(0, vec, candidates, 0, target, candidates.size(), comb);

    // for (const auto &vec : comb)
    // {
    //     for (auto num : vec)
    //     {
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }

    return comb;
}

int main()
{
    vector<int> ar;
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        ar.push_back(a);
    }
    int target;
    cin >> target;

    vector<vector<int>> res = combinationSum(ar, target);

    return 0;
}
