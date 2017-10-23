#include<bits/stdc++.h>

using namespace std;

int main()
{
    int y,np,x,popes[100001],tmp[100001],dif=0,j,mx=-1,strt,ed;

    while(scanf("%d",&y)!=EOF){

        scanf("%d",&np);
        for(int i=0;i<np;i++){
            scanf("%d",&popes[i]);
        }
        mx=-1;
        for(int k=0;k<np-1;k++){
        x=1;j=0;
        tmp[j++]=popes[k];
        for(int i=k+1;i<np;i++){
            dif=popes[i]-popes[i-1];
            x=x+dif;
            if(x<=y){
                tmp[j++]=popes[i];
            }
            else{
                break;
              }
            }
            if(j>mx){
                mx=j;
                strt=tmp[0];
                ed=tmp[mx-1];
            }
          }

          printf("%d %d %d\n",mx,strt,ed);
        }
        return 0;
    }

