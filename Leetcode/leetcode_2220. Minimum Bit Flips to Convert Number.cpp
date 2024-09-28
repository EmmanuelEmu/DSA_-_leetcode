#include <bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal)
{
    int ans = start ^ goal;
    cout << ans << endl;
    int count = 1;
    while (ans > 1)
    {
        int rem = ans % 2;
        if (rem == 1)
        {
            count++;
        }
        ans = ans / 2;
    }
    return count;
}

int main()
{
    int start, goal;
    cin >> start >> goal;
    cout << minBitFlips(start, goal) << endl;
    return 0;
}