#include <bits/stdc++.h>
using namespace std;

// this is very important question asked by microsoft
int getSum(int a, int b)
{
    int sum, carry;
    while (b != 0)
    {
        sum = a ^ b;
        carry = (a & b) << 1;
        a = sum;
        b = carry;
    }
    return a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << getSum(a, b) << endl;
    return 0;
}