class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double, pair<int, int>>,
                       vector<pair<double, pair<int, int>>>,
                       greater<pair<double, pair<int, int>>>>
            minHeap;
        for (int i = 1; i < n; i++) {
            minHeap.push({(double)arr[0] / arr[i], {0, i}});
        }
        while (k > 1) {
            auto top = minHeap.top();
            minHeap.pop();
            int i = top.second.first;
            int j = top.second.second;
            if (i + 1 < j) {
                minHeap.push({(double)arr[i + 1] / arr[j], {i + 1, j}});
            }
            k--;
        }
        return {arr[minHeap.top().second.first],
                arr[minHeap.top().second.second]};
    }
};