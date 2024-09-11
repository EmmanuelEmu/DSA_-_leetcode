#include<bits/stdc++.h>
using namespace std;

int sol(vector<int>& nums, int n, int index, vector<int> &dp){
    if (index >= n)
    {
        return 0;
    }
    if (dp[index]!=-1)
    {
        return dp[index];
    }

    if (nums[index] == 0)
    {
        return INT_MAX;
    }
    
    
    int minVal = INT_MAX;
    for (auto i = 1; i <=nums[index]; i++)
    {
       int nextStep = sol(nums, n, index + i, dp);
        if (nextStep != INT_MAX) {
            minVal = min(minVal, 1 + nextStep);
        }
    }
    return dp[index] = minVal;
}


int jump(vector<int>& nums) {
    vector<int> dp(nums.size(), -1);
     return sol(nums, nums.size()-1, 0, dp);
}

int main(){

    int n;
    vector<int> nums;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    
    cout << jump(nums) << endl; 
    return 0;
}