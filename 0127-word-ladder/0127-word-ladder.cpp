class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        set<string> dict(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        dict.erase(beginWord);
        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (word == endWord) {
                return steps;
            }
            for (auto i = 0; i < word.size(); i++) {
                char originalChar = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (dict.find(word) != dict.end()) {
                        q.push({word, steps + 1});
                        dict.erase(word);
                    }
                }
                word[i] = originalChar;
            }
        }
        return 0;
    }
};