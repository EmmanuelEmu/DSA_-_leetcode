#include <bits/stdc++.h>
using namespace std;

int isSubsequence(const string &s, const string &t, int sIndex)
{
    int i = 0, j = sIndex; // Initialize pointers for `s` and `t`

    while (j < t.length() && i < s.length())
    {
        if (t[j] != s[i])
        {
            return i;
        }
        i++;
        j++;
    }

    return i;
}
int appendCharacters(string s, string t)
{
    int index = -1;
    for(auto i=0; i<s.size(); i++){
        if(s[i] == t[0]){
            index = i;
            break;
        }
    }
    if(index == -1){
        return t.size();
    }
    return t.size() - isSubsequence(t, s, index);
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << appendCharacters(s, t) << endl;
    return 0;
}