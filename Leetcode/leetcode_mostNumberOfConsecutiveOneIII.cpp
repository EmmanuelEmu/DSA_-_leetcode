#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    int l=0,r=0;
    int maxLen = 0;
    int zeros = 0;
    vector<int> ind;
    while (r<nums.size())
    {
        if (nums[r] == 0)
        {
            if (zeros<=k)
            {
                ind.push_back(r);
            }
            
            zeros++;
        }   
        if (zeros>k)
        {
            if (nums[l] == 0)
            {
                zeros--;
                ind.erase(ind.begin());
            }
            l++;
        }
        if (zeros<=k)
        {
            int len = r-l+1;
            maxLen = max(maxLen, len);
        }
        r++;
    }
    for (auto it:ind)
    {
        cout << it << " ";
    }
    cout << endl;
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
    int k;
    cin >> k;
    int result = longestOnes(arr, k);
    cout << result << endl;
    return 0;
}