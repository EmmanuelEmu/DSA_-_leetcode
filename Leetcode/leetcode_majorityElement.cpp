#include <bits/stdc++.h>
using namespace std;

// Using Boyer's Moore voting algorithm

int majorityElement(vector<int> &nums) {
    if (nums.empty()) return -1; // Handle empty vector case

    int candidate = 0, count = 0;

    // Phase 1: Find a candidate
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    // Phase 2: Verify the candidate
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }

    if (count > nums.size() / 2) {
        return candidate;
    } else {
        return -1; // No majority element found
    }
}

int main() {
    vector<int> nums;
    int n;
    cin >> n;
    while (n--) {
        int number;
        cin >> number;
        nums.push_back(number);
    }
    int result = majorityElement(nums);
    cout << result << endl;
    return 0;
}
