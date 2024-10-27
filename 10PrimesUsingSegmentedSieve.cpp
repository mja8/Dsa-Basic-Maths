#include<iostream>
#include<vector>
#include<cmath>
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



vector<bool> primesInSegSieve(int l, int r){
    // generate all primes responsible to mark segSieve using sqrt(r)
    //+1 kiye hai kyoki mera function n-1 tak ka hi prime return
    //krta hai
    vector<bool> sieve = sieveCountingPrimes(sqrt(r)+1);

    // jo upar wale bool array me primes mile hai unko ek jagah store kro
    // base primes me
    vector<int> basePrimes;
    for(int i =0; i<sieve.size(); i++){
        if(sieve[i]==true)
            basePrimes.push_back(i);
    }

    vector<bool> segSieve(r-l+1, true);

    if(l==0){
        segSieve[0] =false;
        segSieve[1] = false;
    }

    if(l==1){
        segSieve[1] = false;
    }

    //ab basePrimes se prime ko nikalo phir usse segmented sieve me primes
    //ko mark karo
    for(int i =0; i<basePrimes.size(); i++){
        //isse hme base prime ka first multiple milega seg sieve ke andar
        int first_mul = (l/basePrimes[i])*basePrimes[i];

        //agar first_mul l se chota hai to next multiple hoga (second multiple)
        if(first_mul < l){
            first_mul = first_mul + basePrimes[i];
        }
        //j me hm purana optimization kr skte hai i*i wala
        int j = max(first_mul, basePrimes[i] * basePrimes[i]);

        while(j <= r){
            segSieve[j - l] = false;
            j = j + basePrimes[i];
        }
    }
    return segSieve;
}


int main()
{

    int l = 0;
    int r = 11;

    vector<bool> ss = primesInSegSieve(l, r);

    for(int i= 0; i<ss.size(); i++){
        if(ss[i] == true)
            cout<<i+l<<" ";
    }

    

return 0;
}