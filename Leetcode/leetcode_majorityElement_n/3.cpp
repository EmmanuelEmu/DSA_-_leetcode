#include <bits/stdc++.h>
using namespace std;

// Function to find all elements that appear more than n/3 times
vector<int> majorityElements(vector<int> &nums) {
    vector<int> result;
    if (nums.empty()) return result;

    // Step 1: Find potential candidates
    int candidate1 = 0, candidate2 = 1, count1 = 0, count2 = 0;

    for (int num : nums) {
        if (num == candidate1) {
            count1++;
        } else if (num == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = num;
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = num;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    // Step 2: Verify the candidates
    count1 = count2 = 0;
    for (int num : nums) {
        if (num == candidate1) count1++;
        else if (num == candidate2) count2++;
    }

    if (count1 > nums.size() / 3) result.push_back(candidate1);
    if (count2 > nums.size() / 3) result.push_back(candidate2);

    return result;
}

int main() {
    vector<int> nums;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    while (n--) {
        int number;
        cin >> number;
        nums.push_back(number);
    }

    vector<int> result = majorityElements(nums);
    if (result.empty()) {
        cout << "No elements appear more than n/3 times." << endl;
    } else {
        cout << "Elements appearing more than n/3 times: ";
        for (int elem : result) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
