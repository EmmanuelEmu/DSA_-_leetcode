#include <bits/stdc++.h>
using namespace std;

vector<int> resultsArray(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> res;

    for (int i = 0; i < n - k + 1; i++)
    {
        bool isValid = true;
        int count = 1;
        int j = i + 1;

        while (j < n && count < k)
        {
            if (nums[j] < nums[j - 1] || nums[j] - nums[j - 1] != 1)
            {
                isValid = false;
                break;
            }
            j++;
            count++;
        }
        if (isValid && count == k)
        {
            res.push_back(nums[j - 1]);
        }
        else
        {
            res.push_back(-1);
        }
    }

    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    while (n--)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    vector<int> res = resultsArray(nums, k);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}