#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (a%b == 0)
    {
        return b;
    }
    return gcd(b, a%b);
}

int findGCD(vector<int> &nums)
{
    auto min = min_element(nums.begin(), nums.end());
    int minNum = *min;

    auto max = max_element(nums.begin(), nums.end());
    int maxNum = *max;

    // cout << minNum << " " << maxNum << endl;
    return gcd(minNum, maxNum);
}

int main()
{

    vector<int> v;
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int result = findGCD(v);
    cout << result << endl;
    return 0;
}