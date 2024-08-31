#include<bits/stdc++.h>
using namespace std;


void subSeq(int ind, vector<int> &res, int arr[], int s, int sum, int n){
    if (ind == n)
    {
        if (s == sum)
        {
            for (auto it : res)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
    res.push_back(arr[ind]);

    s+=arr[ind];
    subSeq(ind+1, res, arr, s, sum, n);

    s-= arr[ind];
    res.pop_back();

    subSeq(ind+1, res, arr, s, sum, n);

}

int main(){


    int arr[] = {1, 2, 1};
    int sum = 2;
    vector<int> vec;
    subSeq(0, vec, arr, 0, sum, 3);
    return 0;
}