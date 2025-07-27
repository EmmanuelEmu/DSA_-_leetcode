class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        string compressed = "";
        int count = 1;
        int index = 0;
        while (index < n) {
            while (index + 1 < n && chars[index] == chars[index + 1]) {
                count++;
                index++;
            }
            compressed += chars[index];
            if (count > 1)
                compressed += to_string(count);
            index++;
            count = 1;
        }
        // cout << compressed << endl; // For debugging purposes
        chars.clear();
        for (auto c : compressed) {
            chars.push_back(c);
        }
        // for (int i = 0; i < chars.size(); ++i)
        // {
        //     cout << chars[i] << " "; // For debugging purposes
        // }
        return compressed.size();
    }
};