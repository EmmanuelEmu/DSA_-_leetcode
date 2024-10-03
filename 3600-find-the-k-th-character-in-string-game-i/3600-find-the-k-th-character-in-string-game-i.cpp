class Solution {
public:
    char nextCharacter(char ch) {
        if (ch >= 'a' && ch <= 'z') { // For lowercase letters
            return (ch == 'z') ? 'a' : ch + 1;
        } else if (ch >= 'A' && ch <= 'Z') { // For uppercase letters
            return (ch == 'Z') ? 'A' : ch + 1;
        } else {
            return ch; // If it's not an alphabetic character, return it as is
        }
    }

    string solve(int k, string str) {
        if (str.size() > k) {
            return str;
        }
        string ans = "";
        for (auto it : str) {
            ans += nextCharacter(it);
        }
        return solve(k, str + ans);
    }

    char kthCharacter(int k) {
        string generatedString = solve(k, "a");
        cout << generatedString << endl;
        return generatedString[k - 1];
    }
};