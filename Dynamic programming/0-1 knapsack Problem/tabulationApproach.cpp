#include <bits/stdc++.h>
using namespace std;


int knapSack(vector<int> wt, vector<int> val, int W)
{
    vector<vector<int>> dp(wt.size(), vector<int>(W + 1, -1));
    for (int w = wt[0]; w <= W; w++)
    {
        dp[0][w] = val[0];
    }
    for (int ind = 1; ind < wt.size(); ind++)
    {
        for (int w = 0; w <= W; w++)
        {
            int notTake = dp[ind - 1][w];
            int take = INT_MIN;
            if (wt[ind] <= w)
            {
                take = val[ind] + dp[ind - 1][w - wt[ind]];
            }
            dp[ind][w] = max(take, notTake);
        }
    }

    return dp[wt.size() - 1][W];
}

int main()
{

    int n;
    vector<int> v;
    vector<int> wt;
    cin >> n;
    while (n--)
    {
        int val, weight;
        cin >> weight >> val;
        v.push_back(val);
        wt.push_back(weight);
    }
    int W;
    cin >> W;
    cout << knapSack(wt, v, W) << endl;
    return 0;
}