#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<pair<int, vector<int>>> vec;

    while (n--) {
        int k;
        cin >> k;
        vector<int> temp;
        while (k--) {
            int a;
            cin >> a; // Read the actual input value
            temp.push_back(a);
        }
        vec.push_back(make_pair(n, temp)); // Use the correct index (n) as the key
    }

    while (q--) {
        int i, j;
        cin >> i >> j;
        cout << vec[i].second[j] << endl;
    }

    return 0;
}
