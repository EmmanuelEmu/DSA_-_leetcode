class Solution {
public:
    // optimal solution using virtual indexing, quickselect and dutch national flag
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find the median
        auto midPtr = nums.begin() + n / 2;
        nth_element(nums.begin(), midPtr, nums.end());
        int median = *midPtr;

        // Step 2: 3-way partition with virtual indexing
        auto A = [&](int i) -> int& { return nums[(1 + 2 * i) % (n | 1)]; };

        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > median) {
                swap(A(i++), A(j++));
            } else if (A(j) < median) {
                swap(A(j), A(k--));
            } else {
                j++;
            }
        }
    }
};