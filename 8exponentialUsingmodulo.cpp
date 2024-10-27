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


//x^n
long long int fastExponential(long long int x,long long int n,long long int M){
    int ans = 1;

    while(n>0){
        if(n&1){ //if n is odd
            ans = (ans * x)%M; //multiply a 1 time (odd time)
        }
        x = (x*x)%M; //multiply a 2 times (even time)
        n>>=1; // n/2  
    }
    return ans;
}
//har bar n/2 ho rha hai (divide and conquer) like binary search
//hence TC : O(log n)


//% M limits the range to [0 to M-1] 


int main()
{
cout<<fastExponential(2,3,100);
return 0;
}