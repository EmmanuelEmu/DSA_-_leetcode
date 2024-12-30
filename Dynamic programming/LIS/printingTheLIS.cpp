#include <bits/stdc++.h>
using namespace std;

vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
{
    // Code here
    vector<int> dp(n, 1);
    int maxi = 1;
    int hash[n];
    int lastIndex = 0;
    for (auto i = 0; i < n; i++)
    {
        hash[i] = i;
        for (auto j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[i] < 1 + dp[j])
            {
                dp[i] = 1 + dp[j];
                hash[i] = j;
            }
        }
        if (maxi < dp[i])
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

int main()
{   
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> res = longestIncreasingSubsequence(n, arr);
    for(auto i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}