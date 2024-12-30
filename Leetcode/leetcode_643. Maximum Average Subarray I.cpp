#include <bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int> &nums, int k)
{
    int n = nums.size();
    int l=0, r=0;
    double sum = 0;
    double maxSum = INT_MIN;
    while(r<n){
        sum += nums[r];
        if(r-l+1 == k){
            maxSum = max(maxSum, sum);
            sum -= nums[l];
            l++;
        }
        r++;
    }
    return maxSum/k;
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
    cout << findMaxAverage(nums, k) << endl;
    return 0;
}