class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);
        vector<int> binaryBoxes(n);
        for (int i = 0; i < n; i++) {
            binaryBoxes[i] = boxes[i] - '0';
        }
        for (auto it : binaryBoxes) {
            cout << it << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && binaryBoxes[j] == 1) {
                    sum += abs(i - j);
                }
            }
            ans[i] = sum;
        }
        return ans;
    }
};