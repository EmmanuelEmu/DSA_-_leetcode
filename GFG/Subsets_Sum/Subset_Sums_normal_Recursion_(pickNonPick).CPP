#include <bits/stdc++.h>
using namespace std;

void subSeq(int ind, vector<int> &res, vector<int> &arr, int s, int n, vector<int> &comb)
{
    if (ind == n)
    {
        comb.push_back(s);
        return;
    }

    res.push_back(arr[ind]);
    s += arr[ind];
    subSeq(ind+1, res, arr, s, n, comb);

    s -= arr[ind];
    res.pop_back();
    subSeq(ind + 1, res, arr, s, n, comb);
}

vector<int> subsetSums(vector<int> &candidates, int n)
{
    vector<int> comb;
    vector<int> vec;
    subSeq(0, vec, candidates, 0, n, comb);
    sort(comb.begin(), comb.end());
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
    vector<int> res = subsetSums(ar, ar.size());
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
