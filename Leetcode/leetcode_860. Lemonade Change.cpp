#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int> &bills)
{
    int hand = 0;
    int five = 0;
    int ten = 0;
    int twenty = 0;
    for (auto i = 0; i < bills.size(); i++)
    {
        if (bills[i] == 5)
        {
            five++;
        }
        else if (bills[i] == 10)
        {
            if (five)
            {
                five--;
                ten++;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(ten && five){
                ten--;
                five--;
            } else if (five>=3){
                five-=3;
            } else{
                return false;
            }
        }
    }

    return true;
}

int main()
{

    return 0;
}