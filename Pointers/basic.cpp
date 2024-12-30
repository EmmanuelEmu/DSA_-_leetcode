#include<bits/stdc++.h>
using namespace std;




int main(){

    int a = 100;
    cout << "The value of a is " << a << endl;
    cout << "The address of a is " << &a << endl;


    // to storing the address value of a variable ---> use the * (asteric) symbol
    int* ptr_a = &a;
    cout << ptr_a << endl;
    cout << *ptr_a << endl;


    float fNumber = 10.9987;
    float* ptr_fNumber = &fNumber;
    cout << ptr_fNumber << endl;
    cout << *ptr_fNumber << endl;


    //storing the address of another pointer to a specific pointer 

    int** ptr_ptr_a = &ptr_a;
    cout << ptr_ptr_a << endl;
    cout << *ptr_ptr_a << endl;
    cout << **ptr_ptr_a << endl;


    int* ptr_rand;
    cout << ptr_rand << endl;
    cout << *ptr_rand << endl;
 


     
    return 0;
}