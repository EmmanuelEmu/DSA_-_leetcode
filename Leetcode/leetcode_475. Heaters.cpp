#include <bits/stdc++.h>
using namespace std;

int findRadius(vector<int> &houses, vector<int> &heaters)
{
    sort(houses.begin(), houses.end());
    auto maxEl = *max_element(houses.begin(), houses.end());
    vector<int> pointer(maxEl, -1);
    int ans = 0;
    for (int i = 0; i < heaters.size(); i++)
    {
        auto it = find(houses.begin(), houses.end(), heaters[i]);
        auto dis = distance(houses.begin(), it);
        pointer[dis] = 1;
        if(dis == 0){
            pointer[dis+1] = 1;
        } else if(dis == houses.size()-1){
            pointer[dis-1] = 1;
        } else {
            pointer[dis-1] = 1;
            pointer[dis+1] = 1;
        }
    }
    for(auto i=0; i<pointer.size(); i++){
        cout << pointer[i] << " ";
    }
    cout << endl;
    for(auto i=0; i<pointer.size(); i++){
        if(pointer[i] == -1){
            ans++;
        }
    }
    return abs(maxEl-ans)+1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> houses;
    vector<int> heaters;
    while (n--)
    {
        int a;
        cin >> a;
        houses.push_back(a);
    }
    while (m--)
    {
        int b;
        cin >> b;
        heaters.push_back(b);
    }
    // findRadius(houses, heaters);
    cout << findRadius(houses, heaters) << endl;
    return 0;
}