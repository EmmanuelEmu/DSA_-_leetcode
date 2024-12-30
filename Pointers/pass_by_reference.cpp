#include<bits/stdc++.h>
using namespace std;


/* 
Passing value to a function 
1. pass by value 

*/


void changeValue(int *ptr){
    *ptr = 20;
}
 
int main(){

    int a = 10;
    changeValue(&a);
    cout << a << endl;
    return 0;
}