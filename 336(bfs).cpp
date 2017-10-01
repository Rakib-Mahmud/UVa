#include<bits/stdc++.h>
#define mx 100
using namespace std;

int main()
{
    int no_edge,co,tst=1,a,b,src,dest,x,y,size,ttl;
    while(1){
    co=0;
    size=0;
    vector<int>edge[mx];
    set<int>::iterator it;
    queue<int>q;
    map<int,int>mp;
    set<int>st;
    scanf("%d",&no_edge);
    if(no_edge==0){ break; }
    for(int i=0;i<no_edge;i++){
        scanf("%d%d",&a,&b);
        x=mp[a];
        if(x==0){
          mp[a]=++size;
          x=size;
        }
        y=mp[b];
        if(y==0){
          mp[b]=++size;
          y=size;
        }
        edge[x].push_back(y);
        edge[y].push_back(x);
        st.insert(x);
        st.insert(y);
    }

    while(1){
    co=0;
    scanf("%d%d",&a,&ttl);
    if(a==0 && ttl==0){ break; }
    x=mp[a];
    src=x;
    for(it=st.begin(); it!=st.end(); ++it){
    dest = *it;
    if(dest==src){ continue; }
    int visited[mx]={0},level[mx]={0};
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
        if(level[dest]>ttl || level[dest]==0){
            co++;
         }
       }
        printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",tst,co,a,ttl);
        tst++;
      }
    }
    return 0;
}
