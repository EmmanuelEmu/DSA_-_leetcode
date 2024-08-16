#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s)
{
    int hash [3] = {-1,-1,-1};
    int cnt=0;
    for (auto i = 0; i < s.size(); i++)
    {
        hash[s[i]-'a'] = i;
        if (hash[0] != -1 && hash[1] != -1 && hash[2] !=-1)
        {
            // cout << hash[0] << " " << hash[1] << " " << hash[2] << endl;
            cnt+= (1+min(hash[0], min(hash[1], hash[2])));
            // cout << cnt << endl;
        }
        
    }
    return cnt;
}

int main()
{

    string s;
    cin >> s;
    int result = numberOfSubstrings(s);
    cout << result << endl;
    return 0;
}