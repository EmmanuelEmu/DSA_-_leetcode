#include <bits/stdc++.h>
using namespace std;

bool carPooling(vector<vector<int>> &trips, int capacity)
{
    vector<pair<int, int>> events;
    for (auto trip : trips)
    {
        events.push_back({trip[1], trip[0]});
        events.push_back({trip[2] , -trip[0]});
    }
    sort(events.begin(), events.end());

    int currentCapacity = 0;

    for(auto event: events){
        currentCapacity+=event.second;
        if (currentCapacity > capacity)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> trips;
    for (auto i = 0; i < n; i++)
    {
        vector<int> trip;
        int a, b, c;
        cin >> a >> b >> c;
        trip.push_back(a);
        trip.push_back(b);
        trip.push_back(c);
        trips.push_back(trip);
    }
    int capacity;
    cin >> capacity;

    cout << carPooling(trips, capacity) << endl;
    return 0;
}