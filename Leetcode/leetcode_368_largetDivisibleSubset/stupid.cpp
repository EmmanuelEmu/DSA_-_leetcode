#include <bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> res;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> numstack;
        numstack.push_back(nums[i]);
        for (int j = i + 1; j < n; j++)
        {
            bool flag = true;
            for (int k = 0; k < numstack.size(); k++)
            {
                if (nums[j] % numstack[k] != 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                numstack.push_back(nums[j]);
            }
        }
        if (numstack.size() > maxLen)
        {
            maxLen = numstack.size();
            res = numstack;
        }
        numstack.clear();
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    while (n--)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    vector<int> res = largestDivisibleSubset(nums);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}