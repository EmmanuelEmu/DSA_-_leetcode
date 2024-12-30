#include <bits/stdc++.h>
using namespace std;

vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    vector<bool> res;

    // Edge case: Single element
    if (n == 1) {
        res.assign(queries.size(), true);
        return res;
    }

    // Step 1: Precompute the "special" array
    vector<bool> special(n, true);
    for (int i = 1; i < n - 1; i++) {
        if (nums[i] % 2 == 0) { // Even
            special[i] = (nums[i - 1] % 2 == 1 && nums[i + 1] % 2 == 1);
        } else { // Odd
            special[i] = (nums[i - 1] % 2 == 0 && nums[i + 1] % 2 == 0);
        }
    }

    // Step 2: Compute prefix sums for "special" array
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + (special[i - 1] ? 1 : 0);
    }

    // Step 3: Process each query using the prefix sum
    for (auto &query : queries) {
        int l = query[0], r = query[1];

        // Single element range is always "special"
        if (l == r) {
            res.push_back(true);
            continue;
        }

        // Boundary conditions for first and last element in the range
        if ((l < n - 1 && nums[l] % 2 == nums[l + 1] % 2) ||
            (r > 0 && nums[r] % 2 == nums[r - 1] % 2)) {
            res.push_back(false);
            continue;
        }

        // Check if all middle elements in the range are "special"
        int countSpecial = prefix[r] - prefix[l + 1];
        res.push_back(countSpecial == (r - l - 1));
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