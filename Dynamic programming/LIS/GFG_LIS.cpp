#include <bits/stdc++.h>
using namespace std;

int longestSubsequence(int n, int a[])
{
    // your code here
    vector<int> dp(n, 1);
    int maxi = 1;
    for (auto i = 0; i < n; i++)
    {
        for(auto j=0; j<i; j++){
            if(a[i]>a[j]){
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}

int main()
{

    return 0;
}