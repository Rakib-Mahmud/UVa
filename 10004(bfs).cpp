#include<bits/stdc++.h>
#define mx 1000
using namespace std;

int main()
{
    int no_edge,no_node,a,b;
    while(1){
    int visited[mx]={0};
    vector<int>edge[mx];
    queue<int>q;

    scanf("%d",&no_node);
    if(no_node==0){ break; }

    scanf("%d",&no_edge);

    for(int i=0;i<no_edge;i++){
        scanf("%d%d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int u,v,p=0,src=0;
    visited[src]=1;
    q.push(src);

    while(!q.empty()){

        u=q.front();
        q.pop();

        for(int j=0;j<edge[u].size();j++){

            v=edge[u][j];
            if(visited[v]==0){

                if(visited[u]==1){
                   visited[v]=2;
                }
                else{
                visited[v]=1;
                }

                q.push(v);

            }
            else{

                if(visited[u]==visited[v]){
                    p=1;
                    break;
                }
            }

        }
        if(p==1){ break; }
      }

      if(p==1){
        printf("NOT BICOLORABLE.\n");
        }

        else{
        printf("BICOLORABLE.\n");
        }

    }

    return 0;
}


