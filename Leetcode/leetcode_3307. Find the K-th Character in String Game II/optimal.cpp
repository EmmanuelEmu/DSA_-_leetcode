#include <bits/stdc++.h>
using namespace std;

char nextCharacter(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    { // For lowercase letters
        return (ch == 'z') ? 'a' : ch + 1;
    }
    else if (ch >= 'A' && ch <= 'Z')
    { // For uppercase letters
        return (ch == 'Z') ? 'A' : ch + 1;
    }
    else
    {
        return ch; // If it's not an alphabetic character, return it as is
    }
}

char kthCharacter(long long k, vector<int> &operations)
{
    string str = "a";
    int stringSize = 1;
    int pre = 0;
    string preStr = "";
    for (int i = 0; i < operations.size(); ++i)
    {
        string newStr = "";

        if (operations[i] == 1)
        {
            for (auto it : str)
            {
                newStr += nextCharacter(it);
            }
            str += newStr;
            preStr = newStr;
            pre = stringSize;
            stringSize += newStr.size();
        } else{
            str += str;
            preStr = str;
            pre = stringSize;
            stringSize += str.size();
        }
        if (stringSize > k)
        {
            // cout << str << endl;
            return preStr[k - pre - 1];
        }
    }
    // cout << str << endl;
    return str[k- 1];
}

int main()
{
    int k;
    cin >> k;
    int n;
    cin >> n;
    vector<int> operations;
    while (n--)
    {
        int a;
        cin >> a;
        operations.push_back(a);
    }
    cout << kthCharacter(k, operations) << endl;
    return 0;
}