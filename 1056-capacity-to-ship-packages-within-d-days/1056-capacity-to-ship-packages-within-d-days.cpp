class Solution {
public:
    bool isCanShip(vector<int>& weights, int capacity, int days) {
        int day = 1;
        int currentWeight = 0;
        for (int weight : weights) {
            if (currentWeight + weight > capacity) {
                day++;
                currentWeight = weight;
            } else {
                currentWeight += weight;
            }
        }
        return day <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        auto low = *max_element(weights.begin(), weights.end());
        auto high = accumulate(weights.begin(), weights.end(), 0);
        int leastCapacity = INT_MAX;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (isCanShip(weights, mid, days)) {
                leastCapacity = min(leastCapacity, mid);
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return leastCapacity == INT_MAX ? low : leastCapacity;
    }
};