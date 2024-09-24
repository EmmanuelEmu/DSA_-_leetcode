#include<bits/stdc++.h>
using namespace std;


// This is the brute force approach of finding the intersection of the two sorted arrays

// Time complexity
// O(n*m)
// Space complexity
// O(m)[for the marked vector] + O(n)[for the res vector]


vector<int> findingintersection(vector<int> &nums1, vector<int> &nums2){
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res;
        vector<int> marked(m, 0);

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (nums1[i] == nums2[j] && marked[j] == 0)
                {
                    res.push_back(nums1[i]);
                    marked[j] = 1;
                    break;
                }

                if(nums1[i] < nums2[j]){
                    break;
                }
                
            }
            
        }

        return res;
        
}

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> nums1, nums2;
    while (n--)
    {
        int a;
        cin >> a;
        nums1.push_back(a);
    }
    while (m--)
    {
        int a;
        cin >> a;
        nums2.push_back(a);
    }
    
    vector<int> res = findingintersection(nums1, nums2);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
    
    return 0;
}