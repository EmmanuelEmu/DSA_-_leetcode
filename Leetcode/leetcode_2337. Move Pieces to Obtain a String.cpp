#include <bits/stdc++.h>
using namespace std;

/*
optimal solution

bool canChange(string start, string target)
{
    int n = start.size();
    int i = 0, j = 0;

    // Traverse both strings
    while (i < n || j < n)
    {
        // Skip underscores in both strings
        while (i < n && start[i] == '_') i++;
        while (j < n && target[j] == '_') j++;

        // If one string ends earlier
        if ((i < n) != (j < n)) return false;

        // If both strings have finished, we are done
        if (i == n && j == n) break;

        // Characters must match
        if (start[i] != target[j]) return false;

        // Check movement rules
        if (start[i] == 'L' && i < j) return false;
        if (start[i] == 'R' && i > j) return false;

        i++;
        j++;
    }

    return true;
}
*/

bool canChange(string start, string target)
{
    int n = start.size();
    int m = target.size();
    if (n != m)
    {
        return false;
    }
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (start[i] == target[j])
        {
            i++;
            j++;
        }
        else
        {
            if ((start[i] == 'L' && target[j] == '_') || (start[i] == '_' && target[j] == 'R'))
            {
                return false;
            }
            else if (start[i] == '_' && target[j] == 'L')
            {
                while (i < n && start[i] != 'L')
                {
                    if(start[i] == 'R'){
                        break;
                    }
                    i++;
                }
                if (start[i] == 'L')
                {
                    swap(start[i], start[j]);
                    j = i;
                }
                else
                {
                    return false;
                }
            }
            else if (start[i] == 'R' && target[j] == '_')
            {
                while (i < n && start[i] != '_')
                {
                    if(start[i] == 'L'){
                        break;
                    }
                    i++;
                }
                if (start[i] == '_')
                {
                    swap(start[i], start[j]);
                    j = i;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    cout << start << endl;
    cout << target << endl;
    if (j == m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string start, target;
    cin >> start >> target;
    cout << canChange(start, target) << endl;
    return 0;
}