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

string solve(int k, vector<int> &operations, string str, int ind)
{
    if (str.size() > k)
    {
        return str;
    }

    if (ind == operations.size())
    {
        return str;
    }

    string ans = "";
    if (operations[ind] == 1)
    {
        for (auto it : str)
        {
            ans += nextCharacter(it);
        }
        str +=ans;
    } else{
        str+=str;
    }

    return solve(k, operations, str, ind + 1);
}

char kthCharacter(long long k, vector<int> &operations)
{
    string generatedString = solve(k, operations, "a", 0);
    cout << generatedString << endl;
    return generatedString[k - 1];
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