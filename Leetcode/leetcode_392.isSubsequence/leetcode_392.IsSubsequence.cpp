#include <bits/stdc++.h>
using namespace std;

bool solve(string s, string t, int ind, int n, string generateS)
{
    if (generateS == s)
    {
        return true;
    }

    if (ind == n)
    {
        return false;
    }

    generateS += t[ind];
    bool pick = solve(s, t, ind + 1, n, generateS);

    generateS.pop_back();
    bool notPick = solve(s, t, ind + 1, n, generateS);

    return pick || notPick;
}

bool isSubsequence(string s, string t)
{
    string generateS = "";
    return solve(s, t, 0, t.size(), generateS);
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << isSubsequence(s, t) << endl;
    return 0;
}