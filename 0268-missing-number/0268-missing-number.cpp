class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool> hash(nums.size()+1, false);

        for(auto it : nums){
            hash[it] = true;
        }

        for(auto i=0; i<=nums.size(); i++){
            if(hash[i] == false){
                return i;
            }
        }
        return -1;
    }
};