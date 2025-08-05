class Solution {
public:
    int maxProbableValue(vector<int>& arr, int k, int maxVal) {
        int n = arr.size();
        int arraySize = 1;
        int elementSum = 0;
        for (int i = 0; i < n; ++i) {
            if (elementSum + arr[i] > maxVal) {
                arraySize++;
                elementSum = arr[i];
            } else {
                elementSum += arr[i];
            }
        }
        return arraySize;
    }

    int findMaxSubArraySum(vector<int>& arr, int k) {
        int lb = *max_element(arr.begin(), arr.end());
        int ub = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;
        while (lb <= ub) {
            int mid = lb + (ub - lb) / 2;
            if (maxProbableValue(arr, k, mid) <= k) {
                ans = mid;
                ub = mid - 1;
            } else {
                lb = mid + 1;
            }
        }
        return ans;
    }

    int splitArray(vector<int>& nums, int k) {
        return findMaxSubArraySum(nums, k);
    }
};