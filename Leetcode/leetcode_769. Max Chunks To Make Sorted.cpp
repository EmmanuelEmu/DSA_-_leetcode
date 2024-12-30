#include <bits/stdc++.h>
using namespace std;

int maxChunksToSorted(vector<int> &arr)
{
    int n = arr.size();
    int prefixSum = 0, sortedPrefixSum = 0, chunks = 0;
    for(auto i=0; i<n; i++){
        prefixSum += arr[i];
        sortedPrefixSum += i;
        if(prefixSum == sortedPrefixSum){
            chunks++;
        }
    }
    return chunks;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    while(n--){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    cout << maxChunksToSorted(arr) << endl;
    return 0;
}