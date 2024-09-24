#include <bits/stdc++.h>
using namespace std;

// This is the brute force solution of the problem

void moveZeros(vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            temp.push_back(nums[i]);
        }
    }

    for (auto i = 0; i < temp.size(); i++)
    {
        nums[i] = temp[i];
    }

    for (auto i = temp.size(); i < n; i++)
    {
        nums[i] = 0;
    }
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr;
    while (n--)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    moveZeros(arr);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}