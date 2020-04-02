#include<bits/stdc++.h>
#define mx 10001
using namespace std;
long long res=-1;
string input[mx],sample;
int weight[mx];
class Trie
{
public:
    //map<char,Trie*>children;
    Trie *children[26];
    bool endOfword;
    int weight;
    Trie(){
        this->endOfword=false;
        this->weight=-1;
        for(int i=0;i<26;i++){
            this->children[i]=nullptr;
        }
    }
    void del();
    void Insert(string word,int w);
    bool Search(string word);
};

void Trie ::del()
{
		for(int i = 0; i < 26; i++)
			if(children[i] != nullptr)
			{
				children[i]->del();
				delete children[i];
			}
}

void Trie ::Insert(string word,int w)
{
    Trie *curr=this;
    int ln=word.size();
    for(int i=0;i<ln;i++){
        int ch;
        ch=word[i]-'a';
        Trie *node=curr->children[ch];
        if(node==nullptr){
            node=new Trie();
            curr->children[ch]=node;
        }
        curr=node;
    }
    curr->endOfword=true;
    curr->weight=w;
}

bool Trie ::Search(string word)
{
    if(this==nullptr)return false;

    Trie *curr=this;
    int ln=word.size();
    for(int i=0;i<ln;i++){
        char ch=word[i];
        Trie *tmp=curr->children[ch];
        if(tmp==nullptr){
            return false;
        }
        curr=tmp;
    }
    return curr->endOfword;
}

int main()
{
   ios::sync_with_stdio(0);
   int t,n;
   cin>>t;
   for(int i=1;i<=t;i++){
    cin>>n;
    res=-1;
    for(int j=0;j<n;j++){
        cin>>input[j];
        cin>>weight[j];
    }
    cin>>sample;
    Trie *root=new Trie();
    for(int j=0;j<n;j++){
        root->Insert(input[j],weight[j]);
    }
    cout<<res<<endl;
    root->del();
    delete root;
   }
   return 0;
}

