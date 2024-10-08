#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int n, int price[], vector<vector<int>> &dp){
    if(ind == 0){
        return n*price[0];
    }
    if(dp[ind][n] != -1){
        return dp[ind][n];
    }
    int notTake = 0 + solve(ind-1, n, price, dp);
    int take = INT_MIN;
    int rodLength = ind+1;
    if(rodLength <= n){
        take = price[ind] + solve(ind, n-rodLength, price, dp);
    }
    return dp[ind][n] = max(take, notTake);
}

int cutRod(int price[], int n)
{
    // code here
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return solve(n-1, n, price, dp);
}
int main()
{

    return 0;
}