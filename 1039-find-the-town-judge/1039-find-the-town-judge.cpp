class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        map<int, int> mp;
        for (auto it : trust) {
            mp[it[0]]--;
            mp[it[1]]++;
        }
        for (auto it : mp) {
            if (it.second == n - 1)
                return it.first;
        }
        return -1;
    }
};