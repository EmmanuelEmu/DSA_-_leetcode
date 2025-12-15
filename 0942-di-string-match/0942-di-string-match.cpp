class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> result;
        int n = s.size();
        int left = 0;
        int right = n;
        for(auto ch : s){
            if(ch == 'I'){
                result.push_back(left);
                left++;
            } else{
                result.push_back(right);
                right--;
            }
        }
        if(s[n-1] == 'D') result.push_back(right);
        else result.push_back(left);

        return result;
    }
};