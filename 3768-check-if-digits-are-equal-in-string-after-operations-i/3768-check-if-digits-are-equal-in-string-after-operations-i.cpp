class Solution {
public:
    bool hasSameDigits(string s) {
        string newString = s;
        while (newString.length() != 2) {
            string temp = "";
            for (int i = 0; i < newString.length() - 1; i++) {
                int sum = (newString[i] - '0') + (newString[i + 1] - '0');
                temp += to_string(sum % 10);
            }
            newString = temp;
        }
        cout << newString << endl;
        return newString[0] == newString[1];
    }
};