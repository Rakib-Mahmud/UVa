#include<bits/stdc++.h>
using namespace std;

int n,mm[1<<13];
int Set(int N,int pos)
{
    return ( N = N | (1<<pos) );
}

bool CK(int N,int pos)
{
    return (bool)( N & (1<<pos) );
}

int Count(int mask)
{
    int c=0;
    for(int i=0;i<12;i++)if(CK(mask,i))c++;
    return c;
}

int reset(int N,int pos)
{
    return (N = N & (~(1<<pos)) );
}

bool basecase(int mask)
{
    int flag=0;
    for(int i=1;i<11;i++){
        if(CK(mask,i)){ if(CK(mask,i+1) && CK(mask,i-1)!=true){ flag=1; break; }}
        if(CK(mask,i)){ if(CK(mask,i+1)!=true && CK(mask,i-1)){ flag=1; break; }}
    }
    if(flag==0){ return true; }
    return false;
}

int dp(int mask)
{
    if(basecase(mask)){
        return Count(mask);
    }

    if(mm[mask]!=-1){
        return mm[mask];
    }

    int mn=1<<20;
    for(int i=1;i<11;i++){
        if(CK(mask,i)){
            if(CK(mask,i+1) && CK(mask,i-1)!=true){
                int k=Set(mask,i-1); k=reset(k,i); k=reset(k,i+1);
                mn=min(mn,dp(k));
            }
            if(CK(mask,i+1)!=true && CK(mask,i-1)){
                int k=Set(mask,i+1); k=reset(k,i); k=reset(k,i-1);
                mn=min(mn,dp(k));
            }
        }
    }
    mm[mask]=mn;
    return mn;
}



int main()
{
    ios::sync_with_stdio(0);
    int t,res;
    string input;
    cin>>t;
    while(t--){
        int mask=0;
        cin>>input;
        memset(mm,-1,sizeof(mm));
        for(int i=11,j=0; i>=0 ;i--,j++){
            if(input[i]=='o')mask=Set(mask,j);
        }//cout<<mask<<endl;
        res=dp(mask);
        //res=Count(res);
        cout<<res<<endl;
    }
    return 0;
}
