#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &digits) {
    int n = digits.size();
    
    // Traverse the vector from the end
    for (int i = n - 1; i >= 0; --i) {
        if (digits[i] < 9) {
            digits[i]++;
            return digits;  // Return the result as no carry is needed
        }
        digits[i] = 0;  // Set current digit to 0 and move to the next
    }

    // If all digits were 9, we need to add an additional digit
    digits.insert(digits.begin(), 1);
    return digits;
}

int main()
{

    vector<int> v;
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    vector<int> result = plusOne(v);
    for (auto i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}