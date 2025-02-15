#include <bits/stdc++.h>
using namespace std;

bool canMakeSubsequence(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    int i = 0, j = 0;
    bool flag = true;
    while (i < n && j < m)
    {
        char ch = str1[i];
        char nextChar = (ch == 'z') ? 'a' : ch + 1;
        if (str1[i] == str2[j] || nextChar == str2[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    if (j == m)
    {
        return true;
    }
    return false;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << canMakeSubsequence(str1, str2) << endl;
    return 0;
}