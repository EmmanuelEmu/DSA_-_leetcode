class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = lower_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
        int right = left + 1;

        vector<int> result;
        while (k > 0) {
            if (left < 0) {
                result.push_back(arr[right++]);
            } else if (right >= n) {
                result.push_back(arr[left--]);
            } else if (abs(arr[left] - x) <= abs(arr[right] - x)) {
                result.push_back(arr[left--]);
            } else {
                result.push_back(arr[right++]);
            }
            k--;
        }

        sort(result.begin(), result.end());
        return result;
    }
};