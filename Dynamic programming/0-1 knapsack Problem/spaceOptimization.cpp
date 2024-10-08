#include <bits/stdc++.h>
using namespace std;

int knapSack(vector<int> wt, vector<int> val, int W)
{
    vector<int> prev(W + 1, 0), curr(W + 1, 0);
    
    // Initialize for the first item
    for (int w = wt[0]; w <= W; w++)
    {
        prev[w] = val[0];
    }
    
    // Loop over items starting from the second one
    for (int ind = 1; ind < wt.size(); ind++)
    {
        for (int w = 0; w <= W; w++)
        {
            int notTake = prev[w];
            int take = INT_MIN;
            if (wt[ind] <= w) // Check if the item can be taken
            {
                take = val[ind] + prev[w - wt[ind]];
            }
            curr[w] = max(take, notTake);
        }
        prev = curr;
    }
    
    return prev[W]; // Final result
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