#include<bits/stdc++.h>
using namespace std;

// using the optimal solution ---> Two pointer approach
// Considering that the given array is already sorted 

void removeDuplicates(vector<int>& nums){
    int ind = 0;
    int n = nums.size();
    for (auto i = ind+1; i < n; i++)
    {
        if (nums[ind] != nums[i] && i!=ind)
        {
            ind++;
            swap(nums[ind], nums[i]);
        }
    }
    
    for(auto it : nums){
        cout << it << " ";
    }
    cout << endl;
}


int main(){

    int n;
    cin >> n;
    vector<int> arr;
    while (n--)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    
    removeDuplicates(arr);
    return 0;
}