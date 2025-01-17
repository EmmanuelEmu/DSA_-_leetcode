class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        if (derived.size() == 1) return derived[0] == 0;
        
        int n = derived.size();
        vector<int> original1, original2;

        original1.push_back(0);
        original2.push_back(1);

        for (int i = 0; i < n - 1; i++) {
            original1.push_back(derived[i] ^ original1.back());
        }

        for (int i = 0; i < n - 1; i++) {
            original2.push_back(derived[i] ^ original2.back());
        }

        bool last1 = (original1.back() ^ original1[0]) == derived[n - 1];
        bool last2 = (original2.back() ^ original2[0]) == derived[n - 1];
        
        return last1 || last2;
    }
};
