#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums, int val)
{
    nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
    for (auto num:nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return nums.size();
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
    int result = removeDuplicates(v,val);
    cout << result << endl;
    return 0;
}