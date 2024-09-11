#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    if (prices.empty())
        return 0;

    int n = prices.size();
    vector<int> leftProfit(n, 0);
    vector<int> rightProfit(n, 0);

    int minPrice = prices[0];
    for (int i = 1; i < n; i++)
    {
        minPrice = min(minPrice, prices[i]);
        leftProfit[i] = max(leftProfit[i - 1], prices[i] - minPrice);
    }
    int maxPrice = prices[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        maxPrice = max(maxPrice, prices[i]);
        rightProfit[i] = max(rightProfit[i + 1], maxPrice - prices[i]);
    }
    int maxTotalProfit = 0;
    for (int i = 0; i < n; i++)
    {
        maxTotalProfit = max(maxTotalProfit, leftProfit[i] + rightProfit[i]);
    }

    return maxTotalProfit;
}


int main()
{
    vector<int> prices;
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        prices.push_back(a);
    }

    int result = maxProfit(prices);
    cout << result << endl;
    return 0;
}