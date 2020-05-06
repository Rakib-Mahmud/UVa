#include<bits/stdc++.h>

using namespace std;

deque<char>res;
int indegree[101],visited[26],flg=0,k=0;
char spec[27],tmp;
void Topsort_Util(multiset<char>adj[],multiset<char>dep[],vector<char>Q,int n);

void Topsort(multiset<char>adj[],multiset<char>dep[],int n)
{
    for(int i=0;i<26;i++)indegree[i]=0;
    for(int i=0;i<26;i++)visited[i]=0;
    for(int j=0;j<n;j++){
        char i=spec[j];
        multiset<char>::iterator it;
        for(it=adj[i].begin();it!=adj[i].end();it++){
            indegree[*it-'a']++;
        }
    }
    priority_queue<char,vector<char>,greater<char> >Qi;
    vector<char>Q;
    for(int j=0;j<n;j++){
        char i=spec[j];
        if(indegree[i-'a']==0){
            Qi.push(i);
        }
    }

    while(!Qi.empty()){
        char u=Qi.top();
        Q.push_back(u);
        Qi.pop();
        multiset<char>::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++){
            if(--indegree[*it-'a']==0){
                Qi.push(*it);
            }
        }
    }
    Topsort_Util(adj,dep,Q,n);
}

void Topsort_Util(multiset<char>adj[],multiset<char>dep[],vector<char>Q,int n)
{
    if(res.size()==n){
        deque<char>::iterator i;
        for(i=res.begin();i!=res.end();i++){
            cout<<*i;
        }cout<<endl; return;
    }
    vector<char>::iterator it;
    for(it=Q.begin();it!=Q.end();it++){
        flg=0;
        if(visited[*it-'a']==0){
            multiset<char>::iterator ip;
            for(ip=dep[*it].begin();ip!=dep[*it].end();ip++){
                if(visited[*ip-'a']!=1){
                    flg=1; break;}
            }
            if(flg==1)continue;
            visited[*it-'a']=1;
            res.push_back(*it);
            Topsort_Util(adj,dep,Q,n);
            res.pop_back();
            visited[*it-'a']=0;
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
    string a,cons;
    while(getline(cin,a)){
        if(k++!=0)cout<<endl;
        int len1=a.size();
        flg=0; res.clear();
        getline(cin,cons);
        int len2=cons.size(),n=(len1+1)/2;
        multiset<char>adj[126],dep[126];
        int j=0;
        for(int i=0;i<len1;i+=2){
            spec[j++]=a[i];
        }
        for(int i=0;i<len2;i=i+4){
            adj[cons[i]].insert(cons[i+2]);
            dep[cons[i+2]].insert(cons[i]);
        }
        Topsort(adj,dep,n);
    }
    return 0;
}
