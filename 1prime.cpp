#include<iostream>
using namespace std;

//Q is count prime upto n-1
//naive approach using loop ke andar loop, TC: O(n*n)


bool isPrime(int n){
    if(n<=1) return false;

    for(int i=2; i<n; i++){
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