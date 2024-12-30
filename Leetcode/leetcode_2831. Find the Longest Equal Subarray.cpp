#include <bits/stdc++.h>
using namespace std;

int longestEqualSubarray(vector<int> &nums, int k)
{
    int n = nums.size();
    int l=0, r=0;
    int count = 0;
    map<int, int> mp;
    int maxLen = 0;
    while(r<n){
        mp[nums[r]]++;
        count = max(count, mp[nums[r]]);
        if(r-l+1-count > k){
            mp[nums[l]]--;
            l++;
        }
        maxLen = max(maxLen, count);
        r++;
    }
    return maxLen;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    while (n--)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cout << longestEqualSubarray(nums, k) << endl;
    return 0;
}