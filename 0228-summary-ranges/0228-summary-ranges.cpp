class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> res;
        if (n == 0)
            return res;

        int start = nums[0];
        int end = nums[0];
        int i = 1;

        while (i < n) {
            if (nums[i] == nums[i - 1] + 1) {
                end = nums[i];
                i++;
            } else {
                if (start == end) {
                    res.push_back(to_string(start));
                } else {
                    res.push_back(to_string(start) + "->" + to_string(end));
                }
                start = nums[i];
                end = nums[i];
                i++;
            }
        }

        // Push the last range after loop ends
        if (start == end) {
            res.push_back(to_string(start));
        } else {
            res.push_back(to_string(start) + "->" + to_string(end));
        }

        return res;
    }
};