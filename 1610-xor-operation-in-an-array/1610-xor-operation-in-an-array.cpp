class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = start;
        for(auto i=1; i<n; i++){
            int num = start+2*i;
            ans ^=num;
        }

        return ans;
    }
};