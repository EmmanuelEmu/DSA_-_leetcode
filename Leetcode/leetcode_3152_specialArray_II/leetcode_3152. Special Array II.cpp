#include <bits/stdc++.h>
using namespace std;

vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();
    vector<bool> res;

    for (auto &query : queries)
    {
        int l = query[0], r = query[1];
        bool isValid = true;

        if (l == r)
        {
            res.push_back(true);
            continue;
        }

        if ((l < n - 1 && nums[l] % 2 == nums[l + 1] % 2) ||
            (r > 0 && nums[r] % 2 == nums[r - 1] % 2))
        {
            res.push_back(false);
            continue;
        }
        for (int i = l + 1; i < r; i++)
        {
            if (nums[i] % 2 == 0)
            { // Even
                if (!(nums[i - 1] % 2 == 1 && nums[i + 1] % 2 == 1))
                {
                    isValid = false;
                    break;
                }
            }
            else
            { // Odd
                if (!(nums[i - 1] % 2 == 0 && nums[i + 1] % 2 == 0))
                {
                    isValid = false;
                    break;
                }
            }
        }

        res.push_back(isValid);
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
    int q;
    cin >> q;
    vector<vector<int>> queries;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        queries.push_back({l, r});
    }
    vector<bool> res = isArraySpecial(nums, queries);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}