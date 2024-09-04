#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{
    auto it = max_element(nums.begin(), nums.end());
    int maxElement = *it;
    vector<int> hash(maxElement+1, 0);

    vector<int> res;
    for (auto it : nums)
    {
        hash[it]++;
    }
    for (auto i = 0; i < hash.size(); i++)
    {
        if (hash[i] > 1)
        {
            res.push_back(i);
        }
        
    }
    
    return res;
}

int main()
{

    return 0;
}