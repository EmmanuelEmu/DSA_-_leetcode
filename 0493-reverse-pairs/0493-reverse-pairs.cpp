class Solution {
public:
    int countReversePairs(std::vector<int>& vec, int left, int mid, int right) {
        int inv_count = 0;
        int j = mid + 1;

        // Count reverse pairs where leftVec[i] > 2 * rightVec[j]
        for (int i = left; i <= mid; ++i) {
            while (j <= right &&
                   static_cast<long long>(vec[i]) > 2LL * vec[j]) {
                ++j;
            }
            inv_count += (j - (mid + 1));
        }

        return inv_count;
    }

    void merge(std::vector<int>& vec, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Create temporary vectors
        std::vector<int> leftVec(n1);
        std::vector<int> rightVec(n2);

        // Copy data to temporary vectors leftVec and rightVec
        for (int i = 0; i < n1; ++i) {
            leftVec[i] = vec[left + i];
        }
        for (int j = 0; j < n2; ++j) {
            rightVec[j] = vec[mid + 1 + j];
        }

        // Merge the temporary vectors back into vec[left..right]
        int i = 0;    // Initial index of first subarray
        int j = 0;    // Initial index of second subarray
        int k = left; // Initial index of merged subarray

        while (i < n1 && j < n2) {
            if (leftVec[i] <= rightVec[j]) {
                vec[k] = leftVec[i];
                ++i;
            } else {
                vec[k] = rightVec[j];
                ++j;
            }
            ++k;
        }

        // Copy the remaining elements of leftVec, if there are any
        while (i < n1) {
            vec[k] = leftVec[i];
            ++i;
            ++k;
        }

        // Copy the remaining elements of rightVec, if there are any
        while (j < n2) {
            vec[k] = rightVec[j];
            ++j;
            ++k;
        }
    }

    int mergeSort(std::vector<int>& vec, int left, int right) {
        int inv_count = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;

            // Sort first and second halves
            inv_count += mergeSort(vec, left, mid);
            inv_count += mergeSort(vec, mid + 1, right);

            // Count reverse pairs before merging
            inv_count += countReversePairs(vec, left, mid, right);

            // Merge the sorted halves
            merge(vec, left, mid, right);
        }
        return inv_count;
    }

    int reversePairs(std::vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};