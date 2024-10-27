//objective : to find primes for given range
#include<iostream>
#include<vector>
using namespace std;

bool isPrime(int n){
    if(n<=1) return false;

    for(int i=2; i<n; i++){
        if(n%i==0) return false;
    }

    return true;
}

void markprime(vector<bool> &array, int n){
    for(int i = 2; i<=n; i++){
        if(array[i] == true){
            if(isPrime(i) == true){
                for(int j=i*2; j<=n; j=j+i){
                    array[j] = false;
                }
            }
        }
    }
}

int main()
{
    int n = 25; //means to find primes upto 25;
    vector<bool> array(n+1, true);

    //mark 0 and 1 as not prime
    array[0] = false;
    array[1] = false;

    //function to mark all primes true inside array
    // markprime(array, n);

    cout<<isPrime(5);

return 0;
}