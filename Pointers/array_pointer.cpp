#include <bits/stdc++.h>
using namespace std;

int main()
{

    int arr[] = {10, 98, 32, 54, 23, 45};


    // here arr is a pointer itself which points the address of the first value of the array
    // if we trying to dereference the address of the array, the we'll get the first element of the array
    cout << arr << endl;
    cout << *arr << endl;



    //finding the sum of the array using pointer
    int sum = 0;
    int* ptr = arr;
    for (auto i = 1; i <=6; i++)
    {
        sum += *(ptr);
        ptr++;
    }
    
    cout << sum << endl;

    return 0;
}