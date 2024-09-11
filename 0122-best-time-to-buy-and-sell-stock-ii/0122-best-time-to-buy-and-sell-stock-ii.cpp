class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;

        int minPrice = prices[0];
        int maxProfit = 0, prevMax = 0;
        int totalProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            maxProfit = max(maxProfit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
            // totalProfit += maxProfit;
            if (maxProfit >= prevMax) {
                totalProfit += maxProfit;
                minPrice = prices[i];
                maxProfit = 0;
            }
            prevMax = maxProfit;
        }

        return totalProfit;
    }
};