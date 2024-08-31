#include <bits/stdc++.h>
using namespace std;

void permutation(vector<int> &arr, vector<int> &ds, vector<bool> &freq, vector<vector<int>> &res){
    if (ds.size() == arr.size())
    {
        res.push_back(ds);
        return;
    }
    for (auto i = 0; i < arr.size(); i++)
    {
        if (!freq[i])
        {
            freq[i] = true;
            ds.push_back(arr[i]);
            permutation(arr, ds, freq, res);

            ds.pop_back();
            freq[i] = false;
        }
        
    }
    
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<vector<int>> per;
    vector<int> ds;
    vector<bool> freq(nums.size(), false);
    permutation(nums, ds, freq, per);

    std::sort(per.begin(), per.end());
    auto it = std::unique(per.begin(), per.end());
    per.resize(std::distance(per.begin(), it));

    return per;

}

int main()
{
    int n;
    vector<int> vec;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    vector<vector<int>> result = permuteUnique(vec);
    for (auto v: result )
    {
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    
    return 0;
}