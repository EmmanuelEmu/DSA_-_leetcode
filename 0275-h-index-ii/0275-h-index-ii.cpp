class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        // sort(citations.begin(), citations.end());
        int hIndex = 0;
        int left = 0, right = n-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            
            int numCite = n-mid;
            if(citations[mid] >= numCite){
                hIndex = numCite;
                right = mid-1;
            } else{
                left = mid+1;
            }
        }
        return hIndex;
    }
};