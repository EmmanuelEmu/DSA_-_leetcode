#include <bits/stdc++.h>
using namespace std;

string makeFancyString(string s)
{
    int n = s.size();
    int count = 1;
    string res = "";
    res += s[0];
    for (auto i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            count++;
        }
        else
        {
            count = 1;
        }
        if (count <= 2)
        {
            res += s[i];
        }
    }
    return res;
}

int main()
{

    return 0;
}