#include <bits/stdc++.h>
using namespace std;

vector<int> pivotArray(vector<int> &nums, int pivot)
{
    vector<int> less, equal, greater;
    for (auto it : nums)
    {
        if (it < pivot)
        {
            less.push_back(it);
        }
        else if (it > pivot)
        {
            greater.push_back(it);
        }
        else
        {
            equal.push_back(it);
        }
    }
    less.insert(less.end(), equal.begin(), equal.end());
    less.insert(less.end(), greater.begin(), greater.end());
    return less;
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
    int pivot;
    cin >> pivot;
    vector<int> res = pivotArray(nums, pivot);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}