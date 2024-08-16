#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int index = -1;
    for (auto i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            return i;
        }
        else if (nums[i] < target)
        {
            // cout << i << endl;
            index = i;
        }
    }
    // cout << index << endl;
    return index + 1;
}

int main()
{

    vector<int> v;
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int val;
    cin >> val;
    int result = searchInsert(v, val);
    cout << result << endl;
    return 0;
}