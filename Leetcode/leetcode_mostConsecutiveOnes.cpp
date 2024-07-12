#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int l=0, r=0;
    int maxLen = 0;
    int cnt = 0;
    while (r<nums.size())
    {
        if (nums[r] == 1)
        {
            cnt++;
            maxLen = max(maxLen,cnt);
        } else
        {
            l = r;
            cnt = 0;
        }
        r++;
    }
    return maxLen;
    
}

int main()
{
    int n;
    vector<int> arr;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    int result = findMaxConsecutiveOnes(arr);
    cout << result << endl;
    return 0;
}