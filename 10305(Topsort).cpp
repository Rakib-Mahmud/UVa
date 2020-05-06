#include<bits/stdc++.h>

using namespace std;

stack<int>res;
int visited[100];
void Topsort_Util(int node,vector<int>adj[]);

void Topsort(vector<int>adj[],int n)
{
    for(int i=0;i<n;i++)visited[i]=0;
    for(int i=0;i<n;i++){
        if(visited[i]!=1){
            Topsort_Util(i,adj);
        }
    }
}

void Topsort_Util(int node,vector<int>adj[])
{
    visited[node]=1;
    vector<int>::iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++){
        if(visited[*it]!=1){
            Topsort_Util(*it,adj);
        }
    }
    res.push(node);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        int n,e,u,v;
        cin>>n>>e;
        if(n==0 && e==0){
            break;
        }
        vector<int>adj[n];
        for(int i=0;i<e;i++){
            cin>>u>>v;
            adj[u-1].push_back(v-1);
        }
        Topsort(adj,n);

        while(!res.empty()){
            cout<<res.top()+1<<" ";
            res.pop();
        }
        cout<<endl;
    }
}
