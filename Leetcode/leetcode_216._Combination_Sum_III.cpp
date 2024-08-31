#include <bits/stdc++.h>
using namespace std;

void subSeq(int ind, vector<int> &result, vector<int> &arr, int s, int target, int n, vector<vector<int>> &comb, int k)
{

    if (s > target)
    {
        return;
    }
    if (ind == n)
    {
        if (s == target && result.size() == k)
        {
            // sort(result.begin(), result.end());
            for (auto it : result)
            {
                if (it > 9 || it<1)
                {
                    return;
                }
            }
            
            comb.push_back(result);
        }
        return;
    }

    result.push_back(arr[ind]);
    s += arr[ind];
    subSeq(ind + 1, result, arr, s, target, n, comb, k);

    result.pop_back();
    s -= arr[ind];

    // while (ind + 1 < n && arr[ind] == arr[ind + 1])
    //     ind++;
    subSeq(ind + 1, result, arr, s, target, n, comb, k);
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> comb;
    vector<int> vec;
    vector<int> candidates;
    for (int i = 1; i <=n; i++)
    {
        candidates.push_back(i);
    }
    // cout << candidates.size() << endl;
    subSeq(0, vec, candidates, 0, n, candidates.size(), comb, k);

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
    int k, n;
    cin >> k >> n;
    vector<vector<int>> result = combinationSum3(k, n);
    for (auto vec : result)
    {
        for (auto num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    // cout << result.size() << endl;
    return 0;
}