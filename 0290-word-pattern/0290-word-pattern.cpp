class Solution {
public:
    void removeTrailingSpaces(std::string& str) {
        // Find the position of the last non-space character
        size_t endPos = str.find_last_not_of(" ");

        // If the string contains only spaces, erase everything
        if (endPos == std::string::npos) {
            str.clear();
        } else {
            // Erase from the last non-space character to the end
            str.erase(endPos + 1);
        }
    }

    bool wordPattern(string pattern, string s) {
        unordered_set<string> wordsUsed;
        map<char, string> mp;
        std::stringstream ss(s);
        std::string word;

        int i = 0;

        while (ss >> word) {
            if (i >= pattern.size()) {
                return false;
            }

            char currentChar = pattern[i];

            if (mp.count(currentChar)) {
                if (mp[currentChar] != word) {
                    return false;
                }
            } else {
                // If the word is already used by another pattern character
                if (wordsUsed.count(word)) {
                    return false; // Word already mapped to another character
                }
                mp[currentChar] = word;
                wordsUsed.insert(word);
            }
            i++;
        }
        if (i != pattern.size()) {
            return false;
        }

        return true;
    }
};