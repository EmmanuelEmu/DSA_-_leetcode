#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &nums)
{
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}

int subs(int ind, vector<int> &result, vector<int> &nums, int cnt, int n, int target)
{
    if (ind == n)
    {
        if (!result.empty()) // Ensure it's a non-empty subsequence
        {
            int min_value = *std::min_element(result.begin(), result.end());
            int max_value = *std::max_element(result.begin(), result.end());
            if (min_value + max_value <= target)
            {
                cnt++;
            }
        }
        return cnt;
    }
    result.push_back(nums[ind]);

    cnt = subs(ind+1, result, nums, cnt, n, target);
    result.pop_back();
    cnt = subs(ind+1, result, nums, cnt, n, target);

    return cnt;
}

int numSubseq(vector<int> &nums, int target)
{
    vector<int> res;
    return subs(0, res, nums, 0, nums.size(), target);
}

int main()
{

    vector<int> arr;
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    int target;
    cin >> target;
    int result = numSubseq(arr, target);
    cout << result << endl;
    return 0;
}