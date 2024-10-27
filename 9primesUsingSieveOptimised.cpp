// Online C++ compiler to run C++ program online
#include<iostream>
#include<vector>
using namespace std;

vector<bool> sieveCountingPrimes(int n){
    
    //ek data structure jo sieve ko store 
    
    //starting me saare numbers n tak ko prime maan ke true kr diya gya h
    vector <bool> sieve(n, true);
    
    // 0 aur 1 to non prime hai
    sieve[0] = sieve[1] = false;
    
    //iterate karo sieve ke indexes ko 
    
    for(int i =2; i*i<=n; i++){ //optimization 2 (outer loop)
    //i*i kyo ki agar i*i, n se bara ho jaye to j sieve se bahar ho jayege
    //for(int i =2; i<n; i++)  unoptimized old code
        if(sieve[i] == true){
            // j variable i ke table ko iterate karega
            //aur i ke table ke saare values ko false kr dega
            
            // int j = i*2
            int j = i*i;  //optimisation 1 (inner loop)
            //first unmarked will start from i*i
            //because 2 to i-1 have marked all the tables befor i*i
            
            while(j<=n){
                sieve[j]=false;
                j = j + i;  //j table ke multiple ke aage jaa rha h
            }
        }
    }
return sieve;
}


int main(){
    int n = 25;
    vector<bool> sieve = sieveCountingPrimes(n);
    
    //counting primes from sieve 
    for(int i =0; i<n; i++){
        if(sieve[i] == true){
            cout<<i<<" ";
        }
    }
    return 0;
}