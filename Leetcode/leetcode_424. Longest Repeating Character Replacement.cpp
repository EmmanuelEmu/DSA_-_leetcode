#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k)
{
    int n = s.size();
    int right = 0, left = 0;
    int maxlen = 0;
    int maxf = 0;
    int hash[26] = {0};
    while (right < n)
    {
        hash[s[right] - 'A']++;
        maxf = max(maxf, hash[s[right] - 'A']);
        while (right - left + 1 - maxf > k)
        {
            hash[s[left] - 'A']--;
            for (auto i = 0; i < 26; i++)
            {
                if (hash[i] > 0)
                {
                    maxf = max(maxf, hash[i]);
                }
            }
            left++;
        }
        if (right - left + 1 - maxf <= k)
        {
            maxlen = right - left + 1;
        }
        right++;
    }

    return maxlen;
}

int main()
{

    return 0;
}