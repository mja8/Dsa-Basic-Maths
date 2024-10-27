#include<iostream>
using namespace std;

//Euclid's gcd theorem
// gcd(a,b)
// a>=b gcd(a-b, b)
// a<b gcd(b-a, a)

int gcd(int a,int b){
    if(a==0) return b;

    if(b==0) return a;

    while(a>0 && b>0){
        if(a>b)
            a = a-b;

        else
            b = b-a;    
    }

    return a==0?b:a;
}


int main()
{
cout<<gcd(24,72);

return 0;
}