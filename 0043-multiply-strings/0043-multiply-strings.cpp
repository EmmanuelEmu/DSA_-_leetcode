class Solution {
public:
    string singleMultiply(string& num, char digit, int zeros) {
        if (digit == '0')
            return "0";
        int carry = 0;
        string result;
        for (int i = num.size() - 1; i >= 0; i--) {
            int prod = (num[i] - '0') * (digit - '0') + carry;
            carry = prod / 10;
            result.push_back((prod % 10) + '0');
        }
        if (carry)
            result.push_back(carry + '0');
        reverse(result.begin(), result.end());
        result.append(zeros, '0');
        return result;
    }

    string pairAddition(string& num1, string& num2) {
        if (num1 == "0")
            return num2;
        if (num2 == "0")
            return num1;
        int carry = 0;
        string result;
        int i = num1.size() - 1, j = num2.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0)
                sum += (num1[i] - '0');
            if (j >= 0)
                sum += (num2[j] - '0');
            carry = sum / 10;
            result.push_back((sum % 10) + '0');
            i--;
            j--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        string result = "0";
        vector<string> partials;
        int zeros = 0;
        for (int i = num2.size() - 1; i >= 0; i--) {
            string partial = singleMultiply(num1, num2[i], zeros);
            partials.push_back(partial);
            zeros++;
        }
        for (auto& partial : partials) {
            result = pairAddition(result, partial);
        }
        return result;
    }
};