#include <bits/stdc++.h>
using namespace std;


void subSeq(int ind, vector<int> &result, vector<int> &arr, int n, vector<vector<int>> &comb)
{
    if (result.size() == n)
    {
        comb.push_back(result);
        return;
    }
    
    if (ind == arr.size()) 
    {
        return;
    }

    // Include the current element
    result.push_back(arr[ind]);
    subSeq(ind + 1, result, arr, n, comb);

    // Exclude the current element
    result.pop_back();
    subSeq(ind + 1, result, arr, n, comb);
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;
    vector<int> arr, result;
    for (auto i = 1; i <= n; i++)
    {
        arr.push_back(i);
    }

    subSeq(0, result, arr, k, res);
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> result = combine(n, k);
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
