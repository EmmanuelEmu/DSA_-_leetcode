#include <bits/stdc++.h>
using namespace std;


bool isSubsequence(const string &s, const string &t) {
    int i = 0, j = 0; // Initialize pointers for `s` and `t`
    
    while (j < t.length() && i < s.length()) {
        if (t[j] == s[i]) {
            i++;
        }
        j++;
    }
    
    return i == s.length();
}

int numMatchingSubseq(string s, vector<string> &words)
{
    int cnt = 0;
    for (auto word : words)
    {
        if (isSubsequence(word, s))
        {
            cnt++;
        }
    }

    return cnt;
}

int main()
{

    return 0;
}