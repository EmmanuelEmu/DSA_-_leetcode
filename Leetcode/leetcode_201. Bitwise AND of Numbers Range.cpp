#include <bits/stdc++.h>
using namespace std;

int rangeBitwiseAnd(int left, int right)
{
    int res = left;
    for (int i = left + 1; i <= right; i++)
    {
        res &= i;
    }
    return res;
}
int main()
{

    return 0;
}