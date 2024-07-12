#include<bits/stdc++.h>
using namespace std;


void printVec(vector<int> &v){
    for (auto i = 0; i < v.size(); i++)
    {
            cout << v[i] << " ";
    }
    
}

void nextPermutation(vector<int> &nums)
{
    int ind = -1;
    int n = nums.size();
    for (auto i = n-2; i >=0; i--)
    {
        if (nums[i] < nums[i+1])
        {
            ind = i;
            break;
        }
        
    }
    if (ind == -1)
    {
        reverse(nums.begin(), nums.end());
    } else
    {
        for (auto i = n-1; i > 0; i--)
        {
            if (nums[i]>nums[ind])
            {
                swap(nums[i],nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ind+1, nums.end());
    }
    
    // printVec(nums);
    
}

int main(){

    int n;
    vector<int> nums;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    
    nextPermutation(nums);
    return 0;
}