class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        int res = 0;
        string temp = s;
        sort(temp.begin(), temp.end());
        cout << temp << endl;
        while (!mp.empty()) {
            auto it = mp.begin();
            if (it->second % 2 != 0) {
                res += 1;
            } else {
                res += 2;
            }
            mp.erase(it);
        }
        return res;
    }
};