#include<bits/stdc++.h>
#define mx 4002
using namespace std;
long long res=0,sz=0;
string input[mx];
class Trie
{
public:
    map<char,Trie*>children;
    //Trie *children[70];
    bool endOfword;
    int counter;
    int prefix;
    Trie(){
        this->counter=0;
        this->endOfword=false;
        this->prefix=0;
        //for(int i=0;i<70;i++)this->children[i]=nullptr;
    }
    int Insert(string word);
};

int Trie ::Insert(string word)
{
    Trie *curr=this;
    int ln=word.size(),con=0,c=0;
    for(int i=0;i<ln;i++){
        int ch;
        ch=word[i];
        Trie *node=curr->children[ch];
        if(node==nullptr){
            node=new Trie();
            curr->children[ch]=node;
        }
        con+=node->prefix;
        curr=node;
        c+=curr->counter;
        if(i+1==ln)con+=curr->counter;
        (curr->prefix)++;
    }
    curr->endOfword=true;
    curr->counter++; ++sz;
    return (con<<1)+(sz)-curr->counter;
}

int main()
{
   ios::sync_with_stdio(0);
   int t=1,n;
   while(1){
    cin>>n;
    if(n==0)return 0;
    res=0; sz=0;
    for(int j=0;j<n;j++)cin>>input[j];
    Trie *root=new Trie();
    for(int j=0;j<n;j++){
        int g=root->Insert(input[j]);
        res+=g;
    }
    cout<<"Case "<<t++<<": "<<res<<endl;
    //root->del();
    delete root;
   }
   return 0;
}

