#include<bits/stdc++.h>
using namespace std;


void printNumber(int i, int n){
    if (i<0)
    {
        return;
    }
    printNumber(i-1, n);
    cout << i << endl;
}

int main(){

    printNumber(10, 10);
    return 0;
}