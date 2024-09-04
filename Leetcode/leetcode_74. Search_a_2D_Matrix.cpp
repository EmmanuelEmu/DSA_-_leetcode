#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    for (auto it : matrix)
    {
        int lb = 0;
        int ub = it.size()-1;

        while (lb<=ub)
        {
            int mid = lb + (ub-lb)/2;
            if (it[mid] == target)
            {
                return true;
            } else if (it[mid] > target)
            {
                ub = mid-1;
            } else{
                lb = mid+1;
            }
            
        }
        
    }
    return false;
}

int main()
{

    return 0;
}