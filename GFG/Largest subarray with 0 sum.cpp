#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int> &arr, int n)
{
    // Your code here
    map<int, int> mp;
    int sum = 0;
    int maxLen = 0;
    int k = 0;
    for (auto i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        int rem = sum - k;
        if (mp.find(rem) != mp.end())
        {
            int len = i - mp[rem];
            maxLen = max(maxLen, len);
        }
        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }
    return maxLen;
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
    int k;
    cin >> k;
    int result = maxLen(arr, n);
    cout << result << endl;
    return 0;
}