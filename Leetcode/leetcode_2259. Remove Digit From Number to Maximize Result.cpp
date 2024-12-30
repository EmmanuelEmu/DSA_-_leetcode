#include <bits/stdc++.h>
using namespace std;

string removeDigit(string number, char digit)
{
    vector<int> idx;
    for (int i = 0; i < number.size(); i++)
    {
        if (number[i] == digit)
        {
            idx.push_back(i);
        }
    }

    string tempStr = number;
    string maxNumber = tempStr.erase(idx[0], 1);

    for (auto id = 1; id < idx.size(); id++)
    {
        tempStr = number;
        tempStr.erase(idx[id], 1);
        for (auto i = 0; i < tempStr.size(); i++)
        {
            if (tempStr[i] > maxNumber[i])
            {
                maxNumber = tempStr;
                break;
            }
            else if (tempStr[i] < maxNumber[i])
            {
                break;
            }
            else
            {
                continue;
            }
        }
    }

    return maxNumber;
}

int main()
{

    string number;
    char digit;
    cin >> number >> digit;
    cout << removeDigit(number, digit) << endl;
    return 0;
}