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

string getPermutation(int n, int k)
{
    vector<vector<int>> per;
    vector<int> ds;
    vector<int> nums;
    for (auto i = 1; i <=n; i++)
    {
        nums.push_back(i);
    }
    
    vector<bool> freq(nums.size(), false);
    permutation(nums, ds, freq, per);

    std::sort(per.begin(), per.end());
    auto it = std::unique(per.begin(), per.end());
    per.resize(std::distance(per.begin(), it));

    vector<int> target = per[k-1];
    
    string res = "";
    for (auto it : target)
    {
        res += to_string(it);
    }

    return res;

}

int main()
{
    int n, k;
    cin >> n >> k;
    string res = getPermutation(n, k);
    cout << res << endl;
    
    return 0;
}