class Solution {
public:
    bool greaterEl(const vector<int>& nums1, int i, const vector<int>& nums2,
                   int j) {
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] > nums2[j])
                return true;
            if (nums1[i] < nums2[j])
                return false;
            ++i;
            ++j;
        }
        return (i != nums1.size()); // true if nums1 has more elements left
    }

    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i = 0, j = 0;
        while (i < nums1.size() || j < nums2.size()) {
            if (greaterEl(nums1, i, nums2, j)) {
                merged.push_back(nums1[i++]);
            } else {
                merged.push_back(nums2[j++]);
            }
        }
        return merged;
    }

    vector<int> getMaxArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (!result.empty() && result.back() < nums[i] &&
                   n - i + j > k) {
                result.pop_back();
                --j;
            }
            if (result.size() < k) {
                result.push_back(nums[i]);
                ++j;
            }
        }
        return result;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> result(k, 0);

        for (int i = max(0, k - n); i <= min(k, m); ++i) {
            vector<int> max1 = getMaxArray(nums1, i);
            vector<int> max2 = getMaxArray(nums2, k - i);
            vector<int> current = merge(max1, max2);
            if (current > result) {
                result = current;
            }
        }

        return result;
    }
};