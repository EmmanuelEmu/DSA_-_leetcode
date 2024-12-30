#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstring(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // applying shifting technique to avoid the -1 based indexing
    for (auto i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (auto j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    int ans = 0;
    for (auto i = 1; i <= n; i++)
    {
        for (auto j = 1; j <= m; j++)
        {
            if (nums1[i - 1] == nums2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}

int findLength(vector<int> &nums1, vector<int> &nums2)
{
    return longestCommonSubstring(nums1, nums2);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums1;
    while (n--)
    {
        int a;
        cin >> a;
        nums1.push_back(a);
    }
    int m;
    cin >> m;
    vector<int> nums2;
    while (m--)
    {
        int a;
        cin >> a;
        nums2.push_back(a);
    }
    cout << findLength(nums1, nums2) << endl;
    return 0;
}