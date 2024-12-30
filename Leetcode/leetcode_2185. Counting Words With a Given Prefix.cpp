#include <bits/stdc++.h>
using namespace std;

int prefixCount(vector<string> &words, string pref)
{
    int count = 0;
    for (auto string : words)
    {
        if (string.find(pref) == 0)
        {
            count++;
        }
    }
    return count;
}

int main()
{

    return 0;
}