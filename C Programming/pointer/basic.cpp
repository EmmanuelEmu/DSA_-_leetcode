#include<bits/stdc++.h>
using namespace std;


int main(){

    int a = 10;
    int* p = &a;
    cout << p << endl;
    cout << *p << endl;
    cout << p+1 << endl;
    cout << *(p+1) << endl;
    *(p+1) = 20;
    cout << *(p+1) << endl;
    return 0;
}