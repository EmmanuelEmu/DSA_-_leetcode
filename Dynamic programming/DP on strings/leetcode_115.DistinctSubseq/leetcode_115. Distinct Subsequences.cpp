#include <bits/stdc++.h>
using namespace std;


int solve(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp)
{
    if(ind2<0) return 1;
    if(ind1<0) return 0;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    if(s1[ind1]==s2[ind2]){
        return dp[ind1][ind2]=solve(ind1-1, ind2-1, s1, s2, dp)+solve(ind1-1, ind2, s1, s2, dp);
    }
    else{
        return dp[ind1][ind2]=solve(ind1-1, ind2, s1, s2, dp);  
    }
}


int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(n-1, m-1, s, t, dp);
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << numDistinct(s1, s2) << endl;
    return 0;
}