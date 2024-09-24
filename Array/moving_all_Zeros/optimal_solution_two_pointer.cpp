#include<bits/stdc++.h>
using namespace std;

void moveZeros(vector<int> &nums)
{
    int n = nums.size();
    int zeroInd = -1;
    for (auto i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            zeroInd = i;
            break;
        }
    }

    for (auto i = zeroInd + 1; i < n; i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[zeroInd]);
            zeroInd++;
        }
    }
    
}

int main(){  
    int n;
    cin>>n;
    vector<int> arr;
    while(n--){
        int a;
        cin>>a;
        arr.push_back(a);
    }

    moveZeros(arr);
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}