#include<bits/stdc++.h>
using namespace std;

int main()
{
    int initial,frst,secnd,thrd;

    while(1){
    scanf("%d%d%d%d",&initial,&frst,&secnd,&thrd);

    if(initial==0 && frst==0 && secnd==0 && thrd==0){
        break;
    }

    int ans=1080;

    if(initial>=frst){
        ans=ans+(initial-frst)*9;
    }
    else{
        ans=ans+(360-((frst-initial)*9));
    }

    if(secnd>=frst){
        ans=ans+(secnd-frst)*9;
    }
    else{
        ans=ans+(360-((frst-secnd)*9));
    }

    if(secnd>=thrd){
        ans=ans+(secnd-thrd)*9;
    }
    else{
        ans=ans+(360-((thrd-secnd)*9));
    }

    printf("%d\n",ans);
  }
  return 0;
}
