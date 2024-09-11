#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        if (nums[0] == 0 && nums.size() > 1) {
            return false;
        }
        dp[0] = true;
        for (auto i = 0; i < nums.size(); i++) {
            if (!dp[i]) {
                continue;
            }
            for (auto j = 1; j <= nums[i] && i + j <= nums.size(); j++) {
                dp[i + j] = true;
                if (dp[nums.size() - 1]) { 
                    return true;
                }
            }
        }
        return dp[nums.size() - 1];
    }
int main()
{

    int n;
    vector<int> nums;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }

    cout << canJump(nums) << endl;
    return 0;
}