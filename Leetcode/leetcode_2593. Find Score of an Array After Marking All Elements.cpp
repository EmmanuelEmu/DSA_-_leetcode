#include <bits/stdc++.h>
using namespace std;

long long findScore(vector<int> &nums)
{
    set<pair<int, int>> st;
    int n = nums.size();
    for (auto i = 0; i < n; i++)
    {
        st.insert({nums[i], i});
    }

    long long res = 0;
    while (st.size() > 0)
    {
        auto minValPair = *st.begin();
        auto minVal = minValPair.first;
        auto minValIdx = minValPair.second;
        res += minVal;
        st.erase(minValPair);

        if (minValIdx - 1 >= 0)
        {
            pair<int, int> p_left = {nums[minValIdx - 1], minValIdx - 1};
            auto it = st.find(p_left);
            if (it != st.end())
            {
                st.erase(it);
            }
        }
        if (minValIdx + 1 <= n - 1)
        {
            pair<int, int> p_right = {nums[minValIdx + 1], minValIdx + 1};
            auto it = st.find(p_right);
            if (it != st.end())
            {
                st.erase(it);
            }
        }
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
    cout << findScore(nums) << endl;
    return 0;
}