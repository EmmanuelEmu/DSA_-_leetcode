#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &dp) {
    if (n==0)
    {
        return 0;
    }   

    if(dp[n]!=-1){
        return dp[n];
    }
    int minVal = n;
    for (auto i = 1; i*i <=n; i++)
    {
        minVal = min(minVal, 1 + solve((n-i*i), dp));
    }
    
    return dp[n] = minVal;
}


int MinSquares(int n){
    vector<int> dp(n+1, -1);
    return solve(n, dp);
}

int main(){

    int n;
    cin >> n;
    cout << MinSquares(n) << endl;
    return 0;
}