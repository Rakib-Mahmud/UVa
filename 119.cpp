#include<bits/stdc++.h>
using namespace std;

int main()
{
    char name[11][13],sub[11][13];
    int n,money,sublist,submoney,temp,c=0;

    while(scanf("%d",&n)!=EOF){
        if(c>0){ printf("\n"); } c++;
        getchar();
        int ara[11]={0};
        for(int i=0;i<n;i++){
            scanf("%s",name[i]);
        }
        for(int k=0;k<n;k++){
        scanf("%s%d%d",sub[0],&money,&sublist);
        getchar();
        if(sublist==0){ continue; }
        for(int i=1;i<=sublist;i++){
            scanf("%s",sub[i]);
        }

        submoney=money/sublist;
        for(int i=0;i<=sublist;i++){
        for(int j=0;j<n;j++){

            if(strcmp(name[j],sub[i])==0 && i==0){
                if(money%sublist==0){ ara[j]=ara[j]-money; }
                else{ ara[j]=ara[j]-(submoney*sublist); }
            }
            else if(strcmp(name[j],sub[i])==0){
                ara[j]=ara[j]+submoney;
            }
        }
      }

    }

    for(int i=0;i<n;i++){
        printf("%s %d\n",name[i],ara[i]);
    }

  }
    return 0;
}
