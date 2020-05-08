#include<bits/stdc++.h>

using namespace std;

int res,flg=0;
int visited[101];
void Topsort_Util(int node,vector<int>adj[]);

void Topsort(vector<int>adj[],int source,int n)
{
    vector<int>ans;
    for(int i=0;i<n;i++)visited[i]=0;
    Topsort_Util(source,adj);
    for(int i=0;i<n;i++){
        if(visited[i]==0)
            ans.push_back(i+1);
    }
    flg=0;
    int ln=ans.size();
    cout<<ln;
    for(int i=0;i<ln;i++)
        cout<<" "<<ans[i];
    cout<<endl;
}

void Topsort_Util(int node,vector<int>adj[])
{
    visited[node]=1;
    if(flg==0){
        flg=1;
        visited[node]=0;
    }
    vector<int>::iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++){
        if(visited[*it]!=1){
            Topsort_Util(*it,adj);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
//    fstream file;
//    file.open("cout.txt", ios::out);
//    streambuf* stream_buffer_cout = cout.rdbuf();
//    streambuf* stream_buffer_file = file.rdbuf();
//    cout.rdbuf(stream_buffer_file);
    int n;
    while(cin>>n && n!=0){
        int e,val,u,v;
        vector<int>adj[n];
        while(cin>>u && u!=0){
            while(cin>>v && v!=0){
                adj[u-1].push_back(v-1);
            }
        }
        cin>>val;
        for(int i=0;i<val;i++){
            cin>>e;
            Topsort(adj,e-1,n);
        }

    }
        return 0;
}
