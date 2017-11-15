#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b,i,j;
    int ml=0;
    vector<int>arrDif;
    ///set<int>::iterator it;
    while(scanf("%d", &n)==1)
    {
        arrDif.clear();
        int flag=0;
        for(i=0;i<n;i++)
        {
        scanf("%d",&a);
        if(i==0){ b=a; }
        else{
            ml=abs(b-a);
            arrDif.push_back(ml);
            b=a;
            }
        }
        if(n==1){
                   printf("Jolly\n"); continue;
               }
        sort(arrDif.begin(),arrDif.end());
        if(arrDif[0]!=1){
                   printf("Not jolly\n"); continue;
               }
        for(i=0; i<n-2; i++){
            if(arrDif[i+1]!=(arrDif[i]+1)){
            flag=1;
            break;
            }
        }

        if(flag==0){
            printf("Jolly\n");
        }
        else{
            printf("Not jolly\n");
        }

    }

   return 0;
}
