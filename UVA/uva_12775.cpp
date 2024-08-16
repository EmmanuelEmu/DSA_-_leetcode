#include <bits/stdc++.h>
using namespace std;

struct Triplets
{
    int x, y, gcd;
};

Triplets extendedEuclidian(int a, int b, int p)
{
    if (b == 0)
    {
        Triplets ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }

    Triplets smallAns = extendedEuclidian(b, a % b, p);
    Triplets ans;
    ans.x = smallAns.y;
    ans.y = smallAns.x - ((a / b) * smallAns.y);
    ans.gcd = smallAns.gcd;

    return ans;
}

int main()
{

    int tc;
    cin >> tc;
    while (tc--)
    {
        int a,b,c,p;
        cin >> a >> b >> c >> p;
        Triplets result = extendedEuclidian(a, b, p);
        cout << result.x << " " << result.y << " " << result.gcd << endl;
    }

    return 0;
}