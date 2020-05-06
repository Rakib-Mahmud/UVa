#include<bits/stdc++.h>

using namespace std;

queue<int>res;
int indegree[101];

void Topsort(multiset<int>adj[],int n)
{
    for(int i=0;i<n;i++)indegree[i]=0;

    for(int i=0;i<n;i++){
        multiset<int>::iterator it;
        for(it=adj[i].begin();it!=adj[i].end();it++){
            indegree[*it]++;
        }
    }
    priority_queue<int,vector<int>,greater<int> >Q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0)
            Q.push(i);
    }

    while(!Q.empty()){
        int u=Q.top();
        Q.pop();
        res.push(u);
        multiset<int>::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++){
            if(--indegree[*it]==0)
                Q.push(*it);
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
        multiset<int>adj[n];
        for(int i=0;i<e;i++){
            cin>>u>>v;
            adj[mp[u]].insert(mp[v]);
        }
        Topsort(adj,n);
        cout<<"Case #"<<test++<<": Dilbert should drink beverages in this order: ";
        while(!res.empty()){
            int value=res.front();
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
