#include<bits/stdc++.h>
#define node pair<int,char>
using namespace std;

int indegree[101],k=0,res;
node spec[27];

void Topsort(multiset<node>adj[])
{
    for(int i=0;i<26;i++)indegree[i]=0;
    for(int j=0;j<26;j++){
        if(spec[j].first!=-1){
            char i=spec[j].second;
            multiset<node>::iterator it;
            for(it=adj[i].begin();it!=adj[i].end();it++){
                indegree[(it->second)-'A']++;
            }
        }
    }
    multiset<node >Q;
    for(int j=0;j<26;j++){
        if(spec[j].first!=-1){
            char i=spec[j].second;
            if(indegree[i-'A']==0){
                Q.insert(spec[j]);
            }
        }
    }

    while(!Q.empty()){
        multiset<node >::iterator it;
        it=Q.begin();
        char u=it->second;
        int tmp=it->first;
        res+=tmp;
        Q.erase(it);
        multiset<node >::iterator i;
        for(i=Q.begin();i!=Q.end(); ){
            node nd;
            nd.first=i->first; nd.second=i->second;
            Q.erase(i++);
            (nd.first)-=tmp;
            Q.insert(nd);
        }
        for(it=adj[u].begin();it!=adj[u].end();it++){
            if(--indegree[(it->second)-'A']==0){
                Q.insert(*it);
            }
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
    string dmo;
    getline(cin,dmo); getline(cin,dmo);
    while(t--){
        for(int i=0;i<26;i++){ spec[i].first=-1; }
        if(k++!=0)cout<<endl;
        multiset<node>adj[126];
        string input; char task,ch;
        int ln=0,days; res=0;
        while(getline(cin,input)){
            ln++;
            if(input.empty())break;
            stringstream ss(input);
            ss>>task;
            ss>>days;
            spec[task-'A'].first=days; spec[task-'A'].second=task;
            node nd;
            nd.first=spec[task-'A'].first; nd.second=task;
            while(ss>>ch){
                adj[ch].insert(nd);
                }
            }
        if(ln==2){ cout<<0<<endl; continue; }
        Topsort(adj);
        cout<<res<<endl;
    }
    return 0;
}
