class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        for (auto i = 0; i < n; i++) {
            auto mul1 = find(arr.begin(), arr.begin() + i, arr[i] * 2);
            auto mul2 = find(arr.begin() + i + 1, arr.end(), arr[i] * 2);
            if (mul1 != arr.begin() + i || mul2 != arr.end()) {
                return true;
            }
        }
        return false;
    }
};