#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string s, int k)
{
    int maxLen = 0;
    int l=0,r=0;
    map<char, int> mp;
    while (r<s.size())
    {
        mp[s[r]]++;
        if (mp[s[r]]>=k)
        {
             maxLen = max(maxLen, (r-l+1));
        }
        
        r++;
    }
    for (auto it:mp)
    {
        cout << it.first << " " << it.second << endl;
    }
    
    return maxLen;
    
}

int main()
{

    string s;
    int k;
    cin >> s >> k;
    int result = longestSubstring(s, k);
    cout << result << endl;

    return 0;
}