#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> w;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i=0,j=0, k=0;
    vector<int> result;
    while (i<m && j<n)
    {
        if (nums1[i] == nums2[j])
        {
            result.push_back(nums1[i]);
            result.push_back(nums2[j]);
            i++;j++;
        }
        else if (nums1[i]<nums2[j])
        {
            result.push_back(nums1[i]);
            i++;
        } else
        {
            result.push_back(nums2[j]);
            j++;
        }
        k++;
    }
    while (i<m)
    {
        result.push_back(nums1[i]);
        i++;
        k++;
    }
    while (j<n)
    {
        result.push_back(nums2[j]);
        j++;
        k++;
    }
    
    nums1 = result;
    // for (auto i = 0; i < nums1.size(); i++)
    // {
    //     cout << nums1[i] << " ";
    // }
    // cout << endl;
}


int main()
{

    int n, m;
    cin >> n >> m;
    while (n--)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    while (m--)
    {
        int b;
        cin >> b;
        w.push_back(b);
    }
    int r1,r2;
    cin >> r1 >> r2;
    merge(v, r1, w, r2);
    return 0;
}