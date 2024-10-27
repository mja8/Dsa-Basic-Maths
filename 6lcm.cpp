#include<iostream>
using namespace std;

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


//we know that : gcd*lcm = a*b

int main()
{
int a = 200;
int b = 12;
int g = gcd(a,b);

int lcm = (a*b)/g;

cout<<lcm;

return 0;
}