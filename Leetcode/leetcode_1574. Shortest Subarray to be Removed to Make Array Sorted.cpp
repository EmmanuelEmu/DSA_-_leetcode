#include <bits/stdc++.h>
using namespace std;

int findLengthOfShortestSubarray(vector<int> &arr)
{
    int n = arr.size();
    int startIndex = -1;
    int endIndex = -1;

    for(auto i=1; i<n; i++){
        if(arr[i] > arr[i+1]){
            startIndex = i;
            break;
        }
    }
    if(startIndex == -1){
        return 0;
    }
    for(auto i=n-1; i>0; i--){
        if(arr[i] < arr[i-1] || arr[i] < arr[startIndex-1]){
            endIndex = i;
            break;
        }
    }
    if(endIndex == -1){
        return 0;
    }   
    cout << startIndex << " " << endIndex << endl;

    return endIndex - startIndex + 1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    while (n--)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    cout << findLengthOfShortestSubarray(arr) << endl;
    return 0;
}