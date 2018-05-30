#include<bits/stdc++.h>
#define mx 100

using namespace std;

map<char,int>mp;

struct node{
    int data;
    int Rank;
}parent[mx];

void makeset(int value)
{
    parent[value].data=value;
    parent[value].Rank=0;
}

int findset(int value)
{
    if(parent[value].data==value){
        return value;
    }
    return parent[value].data=findset(parent[value].data);
}

void Union(int x,int y)
{
    int parent1=findset(x);
    int parent2=findset(y);

    if(parent1==parent2){
        return;
    }

    if(parent[parent1].Rank>=parent[parent2].Rank){
        parent[parent1].Rank = (parent[parent1].Rank == parent[parent2].Rank) ? ++parent[parent1].Rank : parent[parent1].Rank;
        parent[parent2].data=parent1;
    }

    else{
        parent[parent1].data=parent2;
    }
}

bool isUnion(int x,int y)
{
    return findset(x)==findset(y);
}

int main()
{
    for(int i=1,j='A'; j<='Z' ;j++,i++){
        mp[j]=i;
    }
    int t,cont;
    char l;
    char ch[3];
    scanf("%d",&t);

    for(int i=0;i<t;i++){
        if(i!=0){ printf("\n"); }
        for(int k=1;k<=29;k++){ makeset(k); }
        scanf(" %c",&l);
        getchar();
        cont=mp[l]-mp['A']+1;
        while(gets(ch)){
            if(ch[0]=='\0'){ break; }
            if(isUnion(mp[ch[0]],mp[ch[1]])){
                continue;
            }
            else{
                Union(mp[ch[0]],mp[ch[1]]);
                cont--;
            }
        }
        printf("%d\n",cont);
    }
return 0;
}

