#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums, vector<int> &numberStack, int ind,
                  unordered_map<string, vector<int>> &memo)
{
    if (ind == nums.size())
    {
        return numberStack;
    }

    // Create a key for memo based on the current index and the last element
    // in the numberStack (if any)
    string key =
        to_string(ind) +
        (numberStack.empty() ? "-1" : to_string(numberStack.back()));

    if (memo.find(key) != memo.end())
    {
        return memo[key];
    }

    vector<int> pick = {};
    vector<int> nonPick = {};

    if (numberStack.empty() || (nums[ind] % numberStack.back() == 0))
    {
        numberStack.push_back(nums[ind]);
        pick = solve(nums, numberStack, ind + 1, memo);
        numberStack.pop_back(); // Backtrack
    }

    nonPick = solve(nums, numberStack, ind + 1, memo);

    vector<int> res = pick.size() > nonPick.size() ? pick : nonPick;
    memo[key] = res;

    return res;
}

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    vector<int> numberStack;
    unordered_map<string, vector<int>> memo;
    sort(nums.begin(),
         nums.end());
    return solve(nums, numberStack, 0, memo);
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