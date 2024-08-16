#include <bits/stdc++.h>
using namespace std;

int findSpecialInteger(vector<int> &arr)
{
    map<int, int> mp;
    for (auto i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
        if (mp[arr[i]] > (arr.size()/4))
        {
            return arr[i];
        }
        
    }
    return -1;
}

int main()
{

    int n;
    vector<int> nums;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    int result = findSpecialInteger(nums);
    cout << result << endl;
    return 0;
}