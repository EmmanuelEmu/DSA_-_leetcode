class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<long double, pair<int, int>>> fractions;
        int n = arr.size();

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                fractions.push_back({(long double)arr[i] / arr[j], {i, j}});
            }
        }

        auto cmp = [](pair<long double, pair<int, int>>& a,
                      pair<long double, pair<int, int>>& b) {
            return a.first < b.first;
        };

        sort(fractions.begin(), fractions.end(), cmp);

        return {arr[fractions[k - 1].second.first],
                arr[fractions[k - 1].second.second]};
    }
};