#include <bits/stdc++.h>
using namespace std;

bool hasAlternatingBits(int n)
{
    int temp = n;
    int mask = 1;
    while (temp > 1)
    {
        mask = (mask << 1) | 1;
        temp--;
    }
    cout << (n^mask) << endl;
}

int main()
{
    int n;
    cin >> n;
    cout << hasAlternatingBits(n) << endl;
    return 0;
}