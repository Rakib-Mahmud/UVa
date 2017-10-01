#include<bits/stdc++.h>
using namespace std;

#define mx 1000
int primes[mx];

void sieve(int n)
{
    fill_n(primes,n,1);
    primes[0]=0;primes[1]=0;

    for(int i=2;i<=sqrt(n);i++){

        if(primes[i]==1){

            for(int j=2;i*j<=n;j++){
                primes[i*j]=0;
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    sieve(n);
    for(int i=0;i<n;i++){
        if(primes[i]==1){
            cout<<i<<" ";
        }
    }
}
