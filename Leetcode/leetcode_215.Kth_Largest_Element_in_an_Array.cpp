#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    map<int, int> mp;
    for (auto it : nums)
    {
        mp[it]++;
    }

    // map is internally sorted as always
    // sort(mp.begin(), mp.end());
    for(auto it = mp.rbegin(); it!=mp.rend(); it++){
        k-= it->second;
        if (k==0)
        {
            return it->first;
        }   
    }        
}

int main(){

    int n;
    cin >> n;
    vector<int> v;
    while (n--)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int k;
    cin >> k;
    cout << findKthLargest(v, k) << endl;   
    return 0;
}