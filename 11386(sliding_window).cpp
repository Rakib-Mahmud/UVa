#include<bits/stdc++.h>

using namespace std;

long long int input[5001];

int main()
{
    long long int n,flag,x,y,z,tmp,res,cnt_y,cnt_z;
    while(scanf("%lld",&n)==1){
        for(int i=0;i<n;i++){
            scanf("%lld",&input[i]);
        }
        sort(input,input+n);
        x=0; y=1; z=2; res=0;
        while(x<n-2){
            while(z<n && y<n-1){
                if(input[x]+input[y]==input[z]){
                    cnt_y=1; cnt_z=1;
                    while(input[x]+input[++y]==input[z] && y<n-1){ cnt_y++; }
                    while(input[x]+input[y-1]==input[++z] && z<n){ cnt_z++; }
                res=res+(cnt_y*cnt_z);
                }
                else if(input[x]+input[y]<input[z] ){
                    y++;
                }
                else if(input[x]+input[y]>input[z]){
                    z++;
                }

            }
            x++; y=x+1; z=y+1;
        }
        printf("%lld\n",res);
    }
    return 0;
}
