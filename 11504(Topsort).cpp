#include<bits/stdc++.h>

using namespace std;

int res,flg=0;
int visited[100001];
void Topsort_Util(int node,vector<int>adj[]);

void Topsort(vector<int>adj[],vector<int>rev[],int n)
{
    vector<int>prio;
    for(int i=0;i<n;i++){
        visited[i]=0;
        if(rev[i].size()==0)prio.push_back(i);
    }
    res=prio.size();
    //int ln=prio.size();
//    for(int i=0;i<ln;i++){
//        if(visited[prio[i]]!=1){
//            res++; flg=0;
//            Topsort_Util(i,adj);
//        }
//    }
    if(res==0)res++;
}

void Topsort_Util(int node,vector<int>adj[])
{
    visited[node]=1;
//    if(flg==0){
//        vector<int>::iterator i;
//        for(i=rev[node].begin();i!=rev[node].end();i++){
//            if(visited[*i]!=1)
//                Topsort_Util(*i,adj,rev);
//        }
//    }
//    flg=1;
    //visited[node]=1;
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
    int t;
    cin>>t;
    while(t--){
        int n,e,u,v;
        res=0;
        cin>>n>>e;
        vector<int>adj[n],rev[n];
        for(int i=0;i<e;i++){
            cin>>u>>v;
            vector<int>::iterator it;
            it=find(rev[u-1].begin(),rev[u-1].end(),v-1);
            if(it==rev[u-1].end()){
            adj[u-1].push_back(v-1);
            rev[v-1].push_back(u-1);
            }
        }
        Topsort(adj,rev,n);

        cout<<res<<endl;
    }
}
