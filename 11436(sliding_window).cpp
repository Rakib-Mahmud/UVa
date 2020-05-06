#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,i,j,x,y;

    while(1){
        scanf("%lld",&n);
        if(n==0){ break; }

        x=2; y=1; i=0;
        while(x>y){
        if((x*x*x-y*y*y)<n){
            x++;
        }
        else if((x*x*x-y*y*y)>n){
            y++;
        }
        else{ i=1; break; }
        }

        if(i==1){
            printf("%lld %lld\n",x,y);
        }
        else{
            printf("No solution\n");
        }
    }
    return 0;
}
