class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int upperBound = n - 1;
        int lowerBound = 0;
        int firstIndex, secondIndex;
        while (lowerBound < upperBound) {
            if (numbers[lowerBound] + numbers[upperBound] == target) {
                firstIndex = lowerBound + 1;
                secondIndex = upperBound + 1;
                break;
            } else if (numbers[lowerBound] + numbers[upperBound] < target) {
                lowerBound++;
            } else {
                upperBound--;
            }
        }
        return {firstIndex, secondIndex};
    }
};