class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freqMap;
        for (auto& word : words) {
            freqMap[word]++;
        }
        auto cmp = [&](const string& a, const string& b) {
            if (freqMap[a] == freqMap[b]) {
                return a < b;
            }
            return freqMap[a] > freqMap[b];
        };
        priority_queue<string, vector<string>, decltype(cmp)> minHeap(cmp);
        for (auto& entry : freqMap) {
            minHeap.push(entry.first);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        vector<string> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};