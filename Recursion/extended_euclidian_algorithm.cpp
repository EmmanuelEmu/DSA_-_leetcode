#include<bits/stdc++.h>
using namespace std;


struct Triplets
{
    int x,y,gcd;
};

Triplets extendedEuclidian(int a, int b){
    if (b==0)
    {
        Triplets ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }

    Triplets smallAns = extendedEuclidian(b, a%b);
    Triplets ans;
    ans.x = smallAns.y;
    ans.y = smallAns.x - ((a/b)*smallAns.y);
    ans.gcd = smallAns.gcd;

    return ans;
    
}

int main(){

    int a, b;
    cin >> a >> b;
    Triplets result = extendedEuclidian(a,b);
    cout << result.gcd << " " << result.x << " " << result.y <<endl;
    return 0;
}