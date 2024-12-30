#include <bits/stdc++.h>
using namespace std;

long long pickGifts(vector<int> &gifts, int k)
{
    int n = gifts.size();
    sort(gifts.begin(), gifts.end());

    // total number of remaining gifts in the vile
    long long totalGifts = 0;
    for (auto i = 1; i <= k; i++)
    {
        auto idx = max_element(gifts.begin(), gifts.end());
        int dis = distance(gifts.begin(), idx);
        gifts[dis] = floor(sqrt(gifts[dis]));
    }

    for (auto it : gifts)
    {
        totalGifts += it;
    }
    return totalGifts;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> gifts;
    while (n--)
    {
        int a;
        cin >> a;
        gifts.push_back(a);
    }
    cout << pickGifts(gifts, k) << endl;
    return 0;
}