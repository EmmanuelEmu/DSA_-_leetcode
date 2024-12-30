#include <bits/stdc++.h>
using namespace std;

void addContributionToR(int val, vector<int> &bitArray, bool isAdd) {
    int i = 0;
    while (val > 0) {
        // Use bitwise AND to check if the current bit is 1 or 0
        bitArray[i] += (isAdd ? 1 : -1) * (val & 1);
        i++;
        val >>= 1; // Shift right to process the next bit
    }
}

bool isContributionIsEqualToK(vector<int> &bitArray, int k) {
    int bitVectorValue = 0;
    for (int i = 0; i < 32; i++) {
        if (bitArray[i]) {
            bitVectorValue += (1 << i); // Shift to calculate 2^i
        }
    }
    return bitVectorValue >= k;
}

int minimumSubarrayLength(vector<int> &nums, int k) {
    int n = nums.size();
    int minlen = INT_MAX;
    vector<int> bitArray(32, 0);
    int i = 0, j = 0;
    while (j < n) {
        addContributionToR(nums[j], bitArray, true);
        while (isContributionIsEqualToK(bitArray, k)) {
            minlen = min(minlen, j - i + 1);
            addContributionToR(nums[i], bitArray, false);
            i++;
        }
        j++;
    }
    return minlen == INT_MAX ? -1 : minlen;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    while (n--)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cout << minimumSubarrayLength(nums, k) << endl;
    return 0;
}