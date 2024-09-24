#include<bits/stdc++.h>
using namespace std;


// finding the maximum subarrray which sum equals to k
int subArraySumEqualToK(vector<int> &arr, int k){
    int n = arr.size();
    int maxLen = 0;
    int sum = arr[0];
    int count = 0;
    int lb=0, ub=0;
    while (ub<n)
    {
        while (sum>k)
        {
            sum-=arr[lb];
            lb++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, ub-lb+1);
            count++;
        }
        ub++;
        if (ub<n)
        {
            sum+=arr[ub];
        }
    }

    return count;
}

int main(){

    int n;
    cin >> n;
    vector<int> arr;
    while (n--)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    int k;
    cin >> k;
    cout << subArraySumEqualToK(arr, k) << endl;
    return 0;
}