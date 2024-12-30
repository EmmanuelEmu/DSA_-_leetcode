#include <bits/stdc++.h>
using namespace std;

int minimumSumSubarray(vector<int> &nums, int l, int r)
{
    int n = nums.size();
    int lb=0, ub=0;
    int minSum = INT_MAX;
    for(auto i=0; i<n; i++){
        int sum = 0;
        for(auto j=i; j<n; j++){
            sum+=nums[j];
            if(j-i+1 >=l || j-i+1 <=r && sum > 0){
                minSum = min(minSum, sum);
            }
        }
    }
    return minSum;
}

int main()
{

    return 0;
}