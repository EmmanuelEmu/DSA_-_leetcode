#include <bits/stdc++.h>
using namespace std;

long long countQuadruplets(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> pre(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            pre[i][j] = pre[i][j - 1] + (nums[j - 1] < i);
        }
    }

    long long res = 0;
    for (auto j = 0; j < n; j++)
    {
        for (auto k = j + 1; k < n; k++)
        {
            if (nums[j] > nums[k])
            {
                long long potentialI = pre[k][j];
                long long potetialL = (n - nums[j]) - (k - pre[nums[j]][k + 1]);
                res += potentialI * potetialL;
            }
        }
    }

    return res;
}

int main()
{

    return 0;
}