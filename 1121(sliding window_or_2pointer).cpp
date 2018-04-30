#include<bits/stdc++.h>
#define mx 100001
using namespace std;

int main()
{
    long long int N,S,input[mx],sum,res;

    while(scanf("%lld%lld",&N,&S)!=EOF){

        long long int low=0,high=0;
        for(long long int i=0;i<N;i++){
            scanf("%lld",&input[i]);
        }

        res=N+1; sum=input[0];
        while(high<N && low<=high){

            if(sum>=S){
                if((high-low+1)<res){
                    res=high-low+1;
                }
                sum=sum-input[low];
                low++;
            }

            else if(sum<S){
                if(high<N-1){
                    high++;
                    sum+=input[high];
                }
                else{ break; }
            }
        }
        if(res==N+1){
            printf("%d\n",0);
        }
        else
            printf("%lld\n",res);
    }
    return 0;
}
