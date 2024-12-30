#include <bits/stdc++.h>
using namespace std;

vector<int> finalPrices(vector<int> &prices)
{
    int n = prices.size();
    for(auto i = 0; i < n; i++){
        for(auto j = i+1; j < n; j++){
            if(prices[j] <= prices[i]){
                prices[i] -= prices[j];
                break;
            }
        }
    }
    return prices;
}

int main()
{
    
    return 0;
}