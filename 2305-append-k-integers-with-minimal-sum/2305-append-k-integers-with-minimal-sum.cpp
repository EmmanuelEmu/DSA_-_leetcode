class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),
             nums.end()); // Sort nums to handle duplicates and find gaps easily
        long long sum = 0;     // To store the result
        int count = 0;         // Count of numbers added to the sum
        long long current = 1; // Start from the smallest positive integer

        for (int num : nums) {
            while (current < num && count < k) {
                sum += current;
                current++;
                count++;
            }
            if (current == num) {
                current++;
            }
            if (count == k) {
                return sum;
            }
        }
        while (count < k) {
            sum += current;
            current++;
            count++;
        }

        return sum;
    }
};