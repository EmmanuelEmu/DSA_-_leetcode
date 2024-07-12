#include <bits/stdc++.h>
using namespace std;


void printVec(vector<int> &v){
    for (auto i = 0; i < v.size(); i++)
    {
            cout << v[i] << " ";
    }
    
}

void nextPermutation(vector<int> &nums)
{
    vector<int> :: iterator maxElement = std::max_element(nums.begin(), nums.end());
    
    if (nums[0] == (*maxElement))
    {
        vector<int> :: iterator secondMaxElement = std::max_element(nums.begin()+1, nums.end());
        if (nums[1] == (*secondMaxElement))
        {
            std::reverse(nums.begin(), nums.end());
        } else{
            swap(nums[1], nums[2]);
        }
        
    } else
    {
        vector<int> :: iterator maxEl = std::max_element(nums.begin()+1, nums.end());
        if (nums[1]!= (*maxEl))
        {
            swap(nums[1], nums[2]);
        } else
        {
            vector <int> :: iterator immediateValue = std::upper_bound(nums.begin(), nums.end(), nums[0]);
            swap(nums[0], (*immediateValue));
            swap(nums[1], nums[2]);
        }
        
    }  

    printVec(nums);
}

int main()
{

    vector<int> permutation;
    for (auto i = 0; i < 3; i++)
    {
        int input;
        cin >> input;
        permutation.push_back(input);
    }

    nextPermutation(permutation);
    return 0;
}