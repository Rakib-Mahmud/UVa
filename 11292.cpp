#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,m,c,flag;


    while(1){
        c=0; flag=0;
        vector<int>head,knight;
        scanf("%d%d",&n,&m);
        if(n==0 && m==0){ break; }

        for(int i=0;i<n;i++){
            scanf("%d",&t);  head.push_back(t);
        }

        for(int i=0;i<m;i++){
            scanf("%d",&t);  knight.push_back(t);
        }
        sort(head.begin(),head.end());
        sort(knight.begin(),knight.end());
        if(m<n || head[0]>knight[m-1]){
            printf("Loowater is doomed!\n");  continue;
        }

        for(int i=n-1 ; i>=0; i--){
            for(int j=0; j<knight.size(); j++){
                if(knight[j] >= head[i]){
                    c=c+knight[j];
                    knight.erase(knight.begin()+j);
                    flag=0;
                    break;
                }
                else{
                    flag=1;
                }
            }

            if(flag==1){
                break;
            }
        }

        if(flag==1){
            printf("Loowater is doomed!\n");
        }
        else{
            printf("%d\n",c);
        }

    }
    return 0;
}
