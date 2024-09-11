#include<bits/stdc++.h>
using namespace std;

int maxPointsGreek(vector<vector<int>>& arr, int n, int last, vector<vector<int>> &dp){
    if (n==0)
    {
        int maxPoint = 0;
        for (auto i = 0; i < 3; i++)
        {
            if (i!=last)
            {
                maxPoint = max(maxPoint, arr[n][i]);
            }
            
        }
        return maxPoint;
    }

    if (dp[n][last]!=-1)
    {
        return dp[n][last];
    }
    

    int maxPointforGreek = 0;
    for (auto i = 0; i < 3; i++)
    {
        if (i!=last)
        {
            int points = arr[n][i] + maxPointsGreek(arr, n-1, i, dp) ;
            maxPointforGreek = max(maxPointforGreek, points);
        }
        
    }
    return dp[n][last] = maxPointforGreek;
} 


int maximumPoints(vector<vector<int>>& arr, int n) {
    vector<vector<int>> dp(n, vector<int>(4,-1));
    return maxPointsGreek(arr, n-1, 3, dp);
}

int main(){

    
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));
    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    
    // for (auto i = 0; i < n; i++)
    // {
    //     for (auto j = 0; j < 3; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << maximumPoints(arr, n) << endl;
    return 0;
}