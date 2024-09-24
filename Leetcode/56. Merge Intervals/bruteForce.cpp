#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());
    for(auto i=0; i<intervals.size(); i++){
        int start = intervals[i][0];
        int end = intervals[i][1];

        if(!res.empty() && end <= res.back()[1]){
            continue;
        }

        for(auto j=i+1; j<intervals.size(); j++){
            if(intervals[j][0] <= end){
                end = max(end, intervals[j][1]);
            } else{
                break;
            }
        }
        res.push_back({start, end});
    }
    return res;
}

int main()
{

    return 0;
}