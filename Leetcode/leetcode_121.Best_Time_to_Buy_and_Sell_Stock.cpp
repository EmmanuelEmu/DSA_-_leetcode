#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    if (prices.empty())
        return 0;

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        maxProfit = max(maxProfit, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }

    return maxProfit;
}

// int maxProfit(vector<int> &prices)
// {
//     int profit = 0;
//     for (auto i = 0; i < prices.size(); i++)
//     {
//         auto maxElement = max_element(prices.begin()+i+1, prices.end());
//         int currentProfit = (*maxElement) - prices[i];
//         if (currentProfit > profit )
//         {
//             profit = currentProfit;
//         }
        
//     }
//     return profit;

// }

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