#include <bits/stdc++.h>
using namespace std;

int countDigits(int num)
{
    return (num == 0) ? 1 : static_cast<int>(std::log10(std::abs(num)) + 1);
}

string largestNumber(vector<int> &nums)
{
    string res = "";
    sort(nums.begin(), nums.end());
    std::map<int, std::vector<int>> digitGroups;

    for (int num : nums)
    {
        int digits = countDigits(num);
        digitGroups[digits].push_back(num);
    }
    for (const auto &pair : digitGroups)
    {
        string str="";
        for (int num : pair.second)
        {
            str+=std::to_string(num);
        }
        sort(str.begin(), str.end(), greater<char>());
        res+=str;
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    while (n--)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cout << largestNumber(nums) << endl;
    return 0;
}