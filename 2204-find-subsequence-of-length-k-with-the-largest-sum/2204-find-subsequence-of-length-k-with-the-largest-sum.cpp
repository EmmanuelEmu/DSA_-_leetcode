class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<pair<int, int>> maxHeap;
        for (int i = 0; i < n; i++) {
            maxHeap.push({nums[i], i});
        }

        vector<pair<int, int>> topK;
        for (int i = 0; i < k; i++) {
            topK.push_back(maxHeap.top());
            maxHeap.pop();
        }

        sort(topK.begin(), topK.end(),
             [](pair<int, int>& a, pair<int, int>& b) {
                 return a.second < b.second;
             });

        vector<int> res;
        for (auto& elem : topK) {
            res.push_back(elem.first);
        }

        return res;
    }
};