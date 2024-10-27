#include<iostream>
#include<vector>
using namespace std;

//ye siege of Eratosthenes method hai
//counting of primes till n-1


int countPrimes(int n) {
        if(n==0) return 0;
        int count = 0;

        //ye vector 0 se n-1 tk ke number ko true ya false mark krta hai (ki wo prime h ya nhi)
        vector<bool> prime(n, true);

        // 0 aur 1 prime nhi hai 
        prime[0] = prime[1] = false;

        
        for(int i=0; i<n; i++){
            //agar i prime hai to usko count karna hai
            if(prime[i]){
                count++;

                //j i ka table hai i
                int j = i*2;    // j = j + i

                //j ka range n is kam hi hona chahiye
                while(j<n){
                    //i ke saare table ko hm false kr denge kyoki
                    //wo ek baar i ke table me aa gye hai ab wo prime nhi ho skte
                    prime[j] = false; 
                    //j = j + i se hm j ko i ke table me iterate kr skte hai
                    j= j + i;
                }

            }

        }
    return count;
}


int main()
{
cout<<countPrimes(10);
return 0;
}