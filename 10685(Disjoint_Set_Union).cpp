#include<bits/stdc++.h>
#define mx 5001

using namespace std;

vector<int>Rank(mx),parent(mx);
map<string,int>mp;

void makeset(int value)
{
    parent[value]=value;
    Rank[value]=1;
}

int findset(int value)
{
    if(parent[value]==value){
        return value;
    }
    return parent[value]=findset(parent[value]);
}

void Union(int x,int y)
{
    int parent1=findset(x);
    int parent2=findset(y);

    if(parent1==parent2){
        return;
    }

    if(Rank[parent1]>=Rank[parent2]){
        Rank[parent1] = Rank[parent1]+Rank[parent2];
        parent[parent2]=parent1;
    }

    else{
        Rank[parent2] = Rank[parent1]+Rank[parent2];
        parent[parent1]=parent2;
    }
}

bool isUnion(int x,int y)
{
    return findset(x)==findset(y);
}

int main()
{
    string str[mx],s1,s2;
    int C,R,a,b;

    while(1){
        scanf("%d%d",&C,&R);
        if(C==0 && R==0){ break; }
        for(int i=0;i<C;i++){
            cin>>str[i];
            mp[str[i]]=i+1;
            makeset(i+1);
        }
        for(int i=0;i<R;i++){
            cin>>s1>>s2;
            if(isUnion(mp[s1],mp[s2])){ continue; }
            else{
                Union(mp[s1],mp[s2]);
            }
        }
        sort(Rank.begin(),Rank.end());
        printf("%d\n",Rank[5000]);
        fill(parent.begin(),parent.end(),0); fill(Rank.begin(),Rank.end(),0);
        mp.clear();
    }
    return 0;
}
