#include <bits/stdc++.h>
using namespace std;

    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);
        int posInd = 0, negInd = 1;
        for (auto i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                res[negInd] = nums[i];
                negInd += 2;
            }
            else
            {
                res[posInd] = nums[i];
                posInd += 2;
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
    vector<int> res = rearrangeArray(nums);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}