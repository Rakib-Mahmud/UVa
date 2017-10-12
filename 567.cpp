#include<bits/stdc++.h>
#define mx 1000
using namespace std;

int main()
{
    int a,b,src,dest,x,n,p=0;

    while(scanf("%d",&x)!=EOF){
    vector<int>edge[mx];
    queue<int>q;
    p++;

    for(int i=1;i<20;i++){
        if(i==1){ }
        else{ scanf("%d",&x); }
        for(int j=0;j<x;j++){
        scanf("%d",&a);
        edge[i].push_back(a);
        edge[a].push_back(i);
      }
   }

    scanf("%d",&n);

    for(int i=0;i<n;i++){
    int visited[mx]={0},level[mx]={0};
    scanf("%d%d",&src,&dest);

    int u,v;
    visited[src]=1;
    level[src]=0;
    q.push(src);
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int i=0;i<edge[u].size();i++){
            v=edge[u][i];
            if(visited[v]==1){
                continue;
            }
            else{
                visited[v]=1;
                level[v]=level[u]+1;
                q.push(v);
            }
        }
    }
    if(i==0){
    printf("Test Set #%d\n",p);
        }
    if(src>9 && dest>9){
        printf("%d to %d: %d\n",src,dest,level[dest]);
    }
    else if(src<10 && dest<10){
        printf(" %d to  %d: %d\n",src,dest,level[dest]);
    }
    else if(src<10 && dest>9){
        printf(" %d to %d: %d\n",src,dest,level[dest]);
    }
    else{
        printf("%d to  %d: %d\n",src,dest,level[dest]);
    }

       }

       printf("\n");
   }
    return 0;
}
