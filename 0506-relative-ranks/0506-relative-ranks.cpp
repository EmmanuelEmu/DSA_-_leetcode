class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        vector<int> temp = score;
        sort(score.begin(), score.end(), std::greater<int>());
        map<int, string> verdict;
        int n = score.size();

        verdict[score[0]] = "Gold Medal";
        if (n >= 2) {
            verdict[score[1]] = "Silver Medal";
        }
        if (n >= 3) {
            verdict[score[2]] = "Bronze Medal";
        }

        for (auto i = 3; i < n; i++) {
            verdict[score[i]] = to_string(i + 1);
        }

        vector<string> res;
        for (auto i = 0; i < temp.size(); i++) {
            res.push_back(verdict[temp[i]]);
        }

        return res;
    }
};