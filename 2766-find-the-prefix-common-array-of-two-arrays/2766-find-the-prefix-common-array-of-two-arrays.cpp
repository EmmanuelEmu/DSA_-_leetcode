class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        vector<int> hash(51, 0);
        vector<int> ans;
        int count = 0;
        for (int i = 0; i < n; i++) {
            hash[A[i]]++;
            if (hash[A[i]] > 1) {
                count++;
            }
            hash[B[i]]++;
            if (hash[B[i]] > 1) {
                count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};