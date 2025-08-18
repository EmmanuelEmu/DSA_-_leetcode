class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3)
            return false;

        bool isVowel = false;
        bool isConsonant = false;
        bool isNumber = false;
        bool otherChar = false;

        string vowels = "aeiouAEIOU";
        for (auto ch : word) {
            if (vowels.find(ch) != string::npos) {
                isVowel = true;
            } else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                isConsonant = true;
            } else if (ch >= '0' && ch <= '9') {
                isNumber = true;
            } else {
                otherChar = true;
            }
        }

        if (otherChar)
            return false;

        return isVowel && isConsonant;
    }
};