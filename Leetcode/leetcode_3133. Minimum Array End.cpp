#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> getBin(int n)
{
    vector<int> res;
    while (n)
    {
        if (n & 1)
            res.push_back(1);
        else
            res.push_back(0);
        n >>= 1;
    }
    return res;
}

long long minEnd(int n, int x)
{
    if (n == 1)
        return x;

    vector<int> zero_pos;
    int count = 0;
    int val = x;
    while (val)
    {
        if ((val & 1) == 0)
            zero_pos.push_back(count);
        count++;
        val >>= 1;
    }

    int reqd_bits = ceil(log2(n));
    for (int i = zero_pos.size(); i < reqd_bits; ++i)
        zero_pos.push_back(count++);

    vector<int> append_bits = getBin(n - 1);

    ll ans = x;
    int pos = append_bits.size();
    while (pos--)
    {
        if (append_bits.back() == 1)
            ans += pow(2, zero_pos[pos]) * append_bits[pos];
    }
    return ans;
}

int main()
{
    int n, x;
    cin >> n >> x;
    cout << "Result: " << minEnd(n, x) << endl;
    return 0;
}
