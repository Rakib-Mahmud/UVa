#include<bits/stdc++.h>
#define mx 1e8+3
#define ll long long
using namespace std;

ll k=mx;
ll isprime[(ll)mx/32];
bool check(ll N,ll pos)
{
    return (bool)(N & (1<<pos));
}

ll Set(ll N,ll pos)
{
    return N=N | (1<<pos);
}

void sieve(ll n)
{
    ll p=(ll)(sqrt(n));
    for(ll i=3;i<=p;i+=2){
        if(check(isprime[i>>5],i&31)==0){
            for(ll j=i*i;j<=n;j+=(i<<1)){
                isprime[j>>5]=Set(isprime[j>>5],j & 31);
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    sieve(k);
    ll n,a,b;
    while(cin>>n){
        b=((n>>1)%2==0?((n>>1)+1):(n>>1));
        //b=(n/2)+1;
        int flg=0;
        for(ll i=b;i<n;i++){
            if((i%2!=0 && check(isprime[i>>5],i&31)==0) && ((check(isprime[(n-i)>>5],(n-i)&31)==0 && (n-i)%2!=0 && (n-i)!=1) || (n-i)==2)){
                cout<<n<<" is the sum of "<<(n-i)<<" and "<<i<<"."<<endl; flg=1;
                break;
            }
        }
        if(flg==0){
            cout<<n<<" is not the sum of two primes!"<<endl;
        }
    }
    return 0;
}

