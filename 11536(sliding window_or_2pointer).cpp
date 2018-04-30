#include<bits/stdc++.h>

using namespace std;
int input[1000005];
int main()
{
        int low,high,snd_low,T,N,M,K;
        scanf("%d",&T);

        for(int i=1;i<=T;i++){
            low=0; high=0;
            scanf("%d%d%d",&N,&M,&K);
            int cont,ans=N+1;
            if(N==3){
                if(K==2){ ans=2; }
                else if(K==3){ ans=3; }
            }
            input[0]=1; input[1]=2; input[2]=3;
            int visited[105]={0};
            vector<int>ck,index;
            ck.push_back(1); index.push_back(0); ck.push_back(2); index.push_back(1); ck.push_back(3); index.push_back(2); visited[1]=1; visited[2]=2; visited[3]=3;
            high=3; cont=3;
            while(high<N && low<=high){
                if(cont<K){
                    input[high]=((input[high-1]+input[high-2]+input[high-3])%M)+1;
                }
                //cout<<input[high]<<" ";
                if(input[high]>=1 && input[high]<=K && cont<K){
                    if(visited[input[high]]!=0 && ck.front()==input[high]){
                        int pp=ck.front();
                        ck.push_back(pp); ck.erase(ck.begin());
                        index.erase(index.begin()); index.push_back(high); visited[input[high]]=high+1;
                        low=index.front();
                    }

                    else if(visited[input[high]]==0){
                        visited[input[high]]=high+1;
                        ck.push_back(input[high]);
                        index.push_back(high);
                        cont++;
                    }
                    else if(visited[input[high]]!=0){
                        int no=0;
                        for(vector<int>::iterator it=ck.begin();it!=ck.end();it++){

                            if(*it==input[high]){
                                ck.erase(ck.begin()+no); ck.push_back(input[high]);
                                index.erase(index.begin()+no); index.push_back(high);
                                visited[input[high]]=high+1;
                                break;
                            }
                            no++;
                        }
                    }
                    high++;
                }

                else if(cont>=K){
                    int res=high-low;
                    if(res<ans){
                        ans=res;
                    }
                    visited[ck.front()]=0;
                    ck.erase(ck.begin());  index.erase(index.begin()); low=index.front(); cont--;
                }

                else{
                    high++;
                }
            }

            if(ans==N+1){
                printf("Case %d: sequence nai\n",i);
            }
            else{
                printf("Case %d: %d\n",i,ans);
            }

        }
        return 0;
}
