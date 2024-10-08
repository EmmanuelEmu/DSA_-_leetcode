#include <bits/stdc++.h>
using namespace std;

string addStrings(string num1, string num2)
{
    string res = "";
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    string bigNumber = num1.size() >= num2.size() ? num1 : num2;
    string smallNumber = num1.size() < num2.size() ? num1 : num2;
    while (i >= 0 || j >= 0 || carry > 0)
    {
        int sum = carry;
        if (i >= 0)
        {
            sum += num1[i] - '0';
            i--;
        }
        if (j >= 0)
        {
            sum += num2[j] - '0';
            j--;
        }
        res += to_string(sum % 10);
        carry = sum / 10;
    }

    res = string(res.rbegin(), res.rend());
    return res;
}

int main()
{
    string num1, num2;
    cin >> num1 >> num2;
    cout << addStrings(num1, num2) << endl;
    return 0;
}