#include <bits/stdc++.h>
using namespace std;

int solve(int ind, vector<int> &candidates, int andOp, vector<vector<int>> &dp)
{
    if (andOp == 0)
    {
        return 0;
    }
    if (ind == candidates.size())
    {
        if (andOp == 0)
        {
            return 0;
        }
        return 1;
    }
    int take = 1 + solve(ind + 1, candidates, andOp & candidates[ind]);
    int notTake = solve(ind + 1, candidates, andOp);
    return max(take, notTake);
}

int largestCombination(vector<int> &candidates)
{

}

int main()
{

    return 0;
}