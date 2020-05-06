#include<bits/stdc++.h>

using namespace std;

stack<int>res;
int visited[101];
void Topsort_Util(int node,multiset <int,greater <int> >adj[]);

void Topsort(multiset <int,greater <int> >adj[],int n)
{
    for(int i=0;i<n;i++)visited[i]=0;
    for(int i=n-1;i>=0;i--){
        if(visited[i]!=1){
            Topsort_Util(i,adj);
        }
    }
}

void Topsort_Util(int node,multiset <int,greater <int> >adj[])
{
    visited[node]=1;
    //vector<int>::iterator it;
    multiset <int,greater <int> > :: iterator it;
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
    fstream file;
    file.open("cout.txt", ios::out);
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_file = file.rdbuf();
    cout.rdbuf(stream_buffer_file);
    int n,test=1;
    while(cin>>n){
        int e,c=0;
        string str,u,v;
        map<string,int>mp;
        map<string,int>::iterator it;
        for(int i=0;i<n;i++){
            cin>>str;
            mp[str]=c++;
        }
        cin>>e;
        //vector<int>adj[n];
        multiset <int,greater <int> >adj[n];
        for(int i=0;i<e;i++){
            cin>>u>>v;
            adj[mp[u]].insert(mp[v]);
        }
        Topsort(adj,n);
        cout<<"Case #"<<test++<<": Dilbert should drink beverages in this order: ";
        while(!res.empty()){
            int value=res.top();
            for(it=mp.begin();it!=mp.end();it++){
                if(it->second==value){
                    str=it->first;
                    break;
                }
            }
            res.pop();
            cout<<str;
            !res.empty()?cout<<" ":cout<<".";
        }
        cout<<endl<<endl;
    }
}
