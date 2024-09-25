class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int maxCite = INT_MIN;

        for (auto i = 0; i < n; i++) {
            int numCite = n - i;
            int h = min(citations[i], numCite);
            maxCite = max(maxCite, h);
        }

        return maxCite;
    }
};