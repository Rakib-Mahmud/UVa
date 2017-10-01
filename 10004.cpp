#include<bits/stdc++.h>
#define mx 1000
using namespace std;

int main()
{
    /**ifstream inputFile;
    ofstream outputFile;
    inputFile.open("inputFile.txt");
    outputFile.open("outputFile.txt");*/

    int no_edge,a,b,n;

    while(1)
    {

    int visited[mx]={0};
    scanf("%d",&n);
    ///inputFile>>n;
    if(n==0){break;}
    vector<int>edge[mx],color[mx];
    scanf("%d",&no_edge);
    ///inputFile>>no_edge;

    for(int i=0;i<no_edge;i++){
        scanf("%d%d",&a,&b);
        ///inputFile>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int u=0,v=0,p=0;
    for(int i=0;i<n;i++){
               if(visited[i]==0){
                    u=2;
                    visited[i]=u;
                    color[i].push_back(u);
                    }
               else{
                    u=visited[i];
                    color[i].push_back(u);
                    }
        for(int j=0;j<edge[i].size();j++){
            v=edge[i][j];
            if(visited[v]==0){
                if(u==2){
                    visited[v]=1 ;
                    color[i].push_back(1);
                        }
                else{
                    visited[v]=2;
                    color[i].push_back(2);
                    }
                }
               else{
                    p=visited[v];
                    color[i].push_back(p);
               }
        }
    }

    int flag=0;
    for(int i=0;i<n;i++){
            u=color[i][0];
        for(int j=1;j<color[i].size();j++){
            if(u==color[i][j]){
                flag=1;
                break;
            }
        }
        if(flag==1) { break; }
    }

    if(flag==1){
        printf("NOT BICOLORABLE.\n");
        ///outputFile<<"NOT BICOLORABLE.\n";
    }
    else{
        printf("BICOLORABLE.\n");
        ///outputFile<<"BICOLORABLE.\n";
    }

  }
    /**inputFile.close();
    outputFile.close();**/
    return 0;
}

