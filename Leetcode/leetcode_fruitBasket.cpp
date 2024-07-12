#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int> &fruits)
{
    int maxLen = 0, l=0,r=0;
    map<int, int>mp;
    while (r<fruits.size())
    {
        mp[fruits[r]]++;
        if (mp.size()>2)
        {
            mp[fruits[l]]--;
            if (mp[fruits[l]] == 0)
            {
                mp.erase(fruits[l]);
            }
            l++;
        }
        if (mp.size()<=2)
        {
            maxLen = max(maxLen, (r-l+1));
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
    int k;
    cin >> k;
    int result = totalFruit(arr);
    cout << result << endl;
    return 0;
}