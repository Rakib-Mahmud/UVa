#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int fx[]={2,2,-2,-2,-1,1,-1,1};
int fy[]={-1,1,-1,1,2,2,-2,-2};
int level[10][10],vis[10][10];
int row=8,col=8;
void bfs(int sx,int sy)
{
	memset(vis,0,sizeof(vis));
	memset(level,0,sizeof(level));
	vis[sx][sy]=1;
	queue<pii>q;
	q.push(pii(sx,sy));
	while(!q.empty())
	{
		pii top=q.front(); q.pop();
		for(int k=0;k<8;k++)
		{
			int tx=top.first+fx[k];
			int ty=top.second+fy[k];
			if((tx>=1 && tx<=row) && (ty>=1 && ty<=col) && vis[tx][ty]==0)
			{
				vis[tx][ty]=1;
				level[tx][ty]=level[top.first][top.second]+1;
				q.push(pii(tx,ty));
			}
		}
	}
}

int main()
{
    int x,y,sx,sy,dx,dy,res;
    char s[]={'a','b','c','d','e','f','g','h'};
    char ch1,ch2,c;
    map<char,int>mp;
    for(int i=1;i<=8;i++){
        mp[s[i-1]]=i;
    }
    while(scanf("%c",&ch1)!=EOF){
        scanf("%d%c%c%d",&x,&c,&ch2,&y);
        sx=x; sy=mp[ch1]; dx=y; dy=mp[ch2];
        bfs(sx,sy);
        res=level[dx][dy];
        printf("To get from %c%d to %c%d takes %d knight moves.\n",ch1,x,ch2,y,res);
        getchar();
    }
    return 0;
}
