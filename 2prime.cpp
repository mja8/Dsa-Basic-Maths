#include<iostream>
#include<cmath>
using namespace std;

//Q is count prime upto n-1
//approach using sqrt

//since if a number has two factor a and b such that n = a*b
//then for any number we know that, (a>sqrt(n) && b>sqrt(n))  (is not possible)
//so one of the factor a or b must me less than sqrt(n)
//so we can check isPrime condition for i<=sqrt(n)


//so new time complexity is O(n*sqrt(n)) = O(n^3/2)


bool isPrime(int n){
    if(n<=1) return false;

    //we reduced time using sqrt(n)
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0) return false;
    }

    return true;
}


int main()
{
int n=10;
int count = 0;

for(int i=0; i<n; i++){
    if(isPrime(i)){
        count++;
    }
}

cout<<count;


return 0;
}