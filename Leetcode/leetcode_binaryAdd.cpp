#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b)
{
    int i = a.size() - 1;
    int j = b.size() - 1;
    string rest = i > j ? a : b;
    int carry = 0;
    string result = "";
    while (i >= 0 && j >= 0)
    {
        if (((a[i] == '1' && b[j] == '0') || (a[i] == '0' && b[j] == '1')))
        {
            if (carry == 0)
            {
                result += '1';
                carry = 0;
            }
            else
            {
                result += '0';
                carry = 1;
            }
        }
        else if (a[i] == '0' && b[j] == '0')
        {
            if (carry == 0)
            {
                result += '0';
                carry = 0;
            }
            else
            {
                result += '1';
                carry = 0;
            }
        }

        else
        {
            if (carry == 0)
            {
                result += '0';
                carry = 1;
            }
            else
            {
                result += '1';
                carry = 1;
            }
        }

        i--;
        j--;
    }
    int restInd = rest == a ? i : j;
    while (restInd >= 0)
    {
        if (carry == 0)
        {
            result += rest[restInd];
        }
        else
        {
            if (rest[restInd] == '1')
            {
                result += '0';
                carry = 1;
            }
            else
            {
                result += '1';
                carry = 0;
            }
        }
        restInd--;
    }
    if (carry==1)
    {
        result += '1';
    }
    
    reverse(result.begin(), result.end());
    cout << carry << endl;
    return result;
}

int main()
{

    string a, b;
    cin >> a >> b;
    string result = addBinary(a, b);
    cout << result << endl;
    return 0;
}