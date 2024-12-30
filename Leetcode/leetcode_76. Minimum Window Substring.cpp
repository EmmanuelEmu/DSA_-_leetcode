#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    int n = s.size();
    int m = t.size();
    int l = 0, r = 0;
    int minLen = 1e9;
    int count = 0;
    int sIndex = -1;
    map<char, int> mp;
    for (int i = 0; i < m; i++)
    {
        mp[t[i]]++;
    }

    while (r < n)
    {
        if (mp[s[r]] > 0)
            count++;
        mp[s[r]]--;
        while (count == m)
        {
            if (minLen > r - l + 1)
            {
                minLen = r - l + 1;
                sIndex = l;
            }
            mp[s[l]]++;
            if (mp[s[l]] > 0)
                count--;
            l++;
        }
        r++;
    }

    return sIndex == -1 ? "" : s.substr(sIndex, minLen);
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << minWindow(s, t) << endl;
    return 0;
}