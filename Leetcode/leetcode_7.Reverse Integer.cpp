#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    int result = 0, temp = x;
    x = abs(x);
    while (x != 0)
    {
        int d = x % 10;
        x = x / 10;
        if (result > (INT_MAX - d) / 10)
        {
            return 0;
        }
        result = (result * 10) + d;
    }
    if (temp < 0)
    {
        return -result;
    }
    return result;
}

int main()
{

    long long num;
    cin >> num;
    cout << reverse(num) << endl;
    return 0;
}