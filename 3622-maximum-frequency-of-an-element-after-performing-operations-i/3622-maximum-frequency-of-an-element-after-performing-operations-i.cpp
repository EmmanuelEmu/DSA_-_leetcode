class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxEl = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxEl + k + 1, 0);  // Extended range

        map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
            freq[num]++;
        }

        // cumulative Frequency
        for (int i = 1; i < freq.size(); i++) {
            freq[i] += freq[i - 1];
        }

        int maxFrequency = 0;

        // Check all values in the possible range, not just existing ones
        for (int target = 0; target <= maxEl + k; target++) {
            int leftNum = max(0, target - k);
            int rightNum = min((int)freq.size() - 1, target + k);
            
            int totalNumbers = freq[rightNum] - (leftNum > 0 ? freq[leftNum - 1] : 0);
            int targetCount = countMap[target];  // Use countMap for actual count
            
            int neededOperations = totalNumbers - targetCount;
            maxFrequency = max(maxFrequency, targetCount + min(neededOperations, numOperations));
        }

        return maxFrequency;
    }
};