#include<iostream>
using namespace std;

//m^n
int slowExponential(int m, int n){
    int ans = 1;
    for(int i =1; i<=n; i++){
        ans = ans * m;
    }
    return ans;
}


//a^n
int fastExponential(int a, int n){
    int ans = 1;

    while(n>0){
        if(n&1){ //if n is odd
            ans = ans * a; //multiply a 1 time (odd time)
        }
        a = a*a; //multiply a 2 times (even time)
        n>>=1; // n/2
    }
    return ans;
}
//har bar n/2 ho rha hai (divide and conquer) like binary search
//hence TC : O(log n)


int main()
{
cout<<fastExponential(2,3);
return 0;
}