#include<bits/stdc++.h>
#define mx 100005
using namespace std;

struct node{
    int value,freq,leftmost,rightmost;
};

int input[mx],tst1=0,tst2=0,tmp1=0,tmp2=0,flag=0;
node tree[3*mx];

void make_tree(int nod,int i,int j)
{
    if(i==j){
        tree[nod].value=input[i];
        tree[nod].freq=1;
        tree[nod].leftmost=input[i];
        tree[nod].rightmost=input[i];

        if(tst1==1){ tst2=1; }
        else{ tst1=1; }
        return;
    }

    int left=2*nod;
    int right=2*nod+1;
    int mid=(i+j)/2;

    make_tree(left,i,mid);
    make_tree(right,mid+1,j);

    if(tst1==1 && tst2==1){
            tst1=0; tst2=0;
            if(tree[left].value==tree[right].value){
                    tree[nod].freq=2;
                    tree[nod].value=tree[right].value;
                    tree[nod].leftmost=tree[left].leftmost;
                    tree[nod].rightmost=tree[right].rightmost;
                }
            else{
                    tree[nod].freq=1;
                    tree[nod].value=tree[right].value;
                    tree[nod].leftmost=tree[left].leftmost;
                    tree[nod].rightmost=tree[right].rightmost;
            }
    }
    else if(tst1==1 && tst2==0){
            tst1=0;
        if(tree[left].value==tree[right].value){
            tree[nod].value=tree[left].value;
            tree[nod].freq=tree[left].freq+1;
        }
        else if(tree[left].value!=tree[right].value){
            if(tree[left].freq>tree[right].freq){
                tree[nod].freq=tree[left].freq; tree[nod].value=tree[left].value;
            }
            else{
            tree[nod].value=tree[right].value;
            tree[nod].freq=tree[right].freq;
            }
        }

    }

    else{
        if(tree[left].value==tree[right].value){
            tree[nod].value=tree[right].value;
            tree[nod].freq=tree[left].freq+tree[right].freq;
        }
        else if(tree[left].value!=tree[right].value && tree[left].freq==tree[right].freq){
            if(tree[left].value==tree[left].rightmost && tree[left].rightmost==tree[right].leftmost){
                int cont=0;
                for(int k=mid+1;k<=j;k++){
                    if(input[k]!=tree[left].value){ break; }
                    cont++;
                }
                tree[nod].value=tree[left].value;
                tree[nod].freq=tree[left].freq+cont;
            }
            else if(tree[right].value==tree[left].rightmost && tree[right].value==tree[right].leftmost){
                int cont=0;
                for(int k=mid;k>=i;k--){
                    if(input[k]!=tree[right].value){ break; }
                    cont++;
                }
                tree[nod].value=tree[right].value;
                tree[nod].freq=tree[right].freq+cont;
            }
            else if(tree[left*2+1].value==tree[right*2].value){
                if(tree[left*2+1].freq+tree[right*2].freq>tree[right].freq && tree[left*2+1].freq+tree[right*2].freq>tree[left].freq){
                    tree[nod].freq=tree[left*2+1].freq+tree[right*2].freq;
                    tree[nod].value=tree[left*2+1].value;
                }
                else{
                tree[nod].freq=tree[right].freq;
                tree[nod].value=tree[right].value;
            }
            }
            else{
                tree[nod].freq=tree[right].freq;
                tree[nod].value=tree[right].value;
            }
        }

            else if(tree[left].value!=tree[right].value && tree[left].freq!=tree[right].freq){
                if(tree[left].freq<tree[right].freq){
                    if(tree[left].value==tree[left].rightmost && tree[left].rightmost==tree[right].leftmost){
                    int cont=0;
                    for(int k=mid+1;k<=j;k++){
                        if(input[k]!=tree[left].value){ break; }
                        cont++;
                }
                if((tree[left].freq+cont)>tree[right].freq){
                    tree[nod].freq=tree[left].freq+cont; tree[nod].value=tree[left].value;
                }
                else{
                    tree[nod].freq=tree[right].freq; tree[nod].value=tree[right].value;
                   }
                  }

                else if(tree[right].value==tree[left].rightmost && tree[left].rightmost==tree[right].leftmost){
                    int cont=0;
                    for(int k=mid;k>=i;k--){
                        if(input[k]!=tree[right].value){ break; }
                        cont++;
                }
                tree[nod].freq=tree[right].freq+cont; tree[nod].value=tree[right].value;

                }
                else if(tree[left*2+1].value==tree[right*2].value){
                if(tree[left*2+1].freq+tree[right*2].freq>tree[right].freq && tree[left*2+1].freq+tree[right*2].freq>tree[left].freq){
                    tree[nod].freq=tree[left*2+1].freq+tree[right*2].freq;
                    tree[nod].value=tree[left*2+1].value;
                }
                else{
                tree[nod].freq=tree[right].freq;
                tree[nod].value=tree[right].value;
            }
            }
                else{
                    tree[nod].value=tree[right].value;
                    tree[nod].freq=tree[right].freq;
                }
              }

                else if(tree[left].freq>tree[right].freq){
                    if(tree[right].value==tree[left].rightmost && tree[left].rightmost==tree[right].leftmost){
                    int cont=0;
                    for(int k=mid;k>=i;k--){
                        if(input[k]!=tree[right].value){ break; }
                        cont++;
                }
                if((tree[right].freq+cont)>tree[left].freq){
                    tree[nod].freq=tree[right].freq+cont; tree[nod].value=tree[right].value;
                }
                else{
                    tree[nod].freq=tree[left].freq; tree[nod].value=tree[left].value;
                   }
                }

                 else if(tree[left].value==tree[left].rightmost && tree[left].rightmost==tree[right].leftmost){
                    int cont=0;
                    for(int k=mid+1;k<=j;k++){
                        if(input[k]!=tree[left].value){ break; }
                        cont++;
                }
                tree[nod].freq=tree[left].freq+cont; tree[nod].value=tree[left].value;

                }
                else if(tree[left*2+1].value==tree[right*2].value){
                if(tree[left*2+1].freq+tree[right*2].freq>tree[right].freq && tree[left*2+1].freq+tree[right*2].freq>tree[left].freq){
                    tree[nod].freq=tree[left*2+1].freq+tree[right*2].freq;
                    tree[nod].value=tree[left*2+1].value;
                }
                else{
                tree[nod].freq=tree[left].freq;
                tree[nod].value=tree[left].value;
            }
            }
                else{
                    tree[nod].value=tree[left].value;
                    tree[nod].freq=tree[left].freq;
                }
            }
          }
      }

        tree[nod].leftmost=tree[left].leftmost;
        tree[nod].rightmost=tree[right].rightmost;
}

node query(int nod,int b,int e,int i,int j)
{
    if(b>=i && e<=j){
        if(flag==0){
        tst1=b; tst2=e;
        flag=1;
        }
        else if(flag==1){
            tmp1=b; tmp2=e;
            flag=2;
        }
        return tree[nod];
    }

    else if(b>j || e<i){
        node pp;
        pp.freq=0; pp.value=0; pp.leftmost=0; pp.rightmost=0;
        return pp;
    }

    else {
        int left=2*nod;
        int right=2*nod+1;
        int mid=(b+e)/2;
        node ob1,ob2,ob;
        ob1=query(left,b,mid,i,j);  ob2=query(right,mid+1,e,i,j);

        if(ob1.value==ob2.value || ob1.freq==0 || ob2.freq==0){
            if(ob2.freq==0){
                ob.freq=ob1.freq; ob.value=ob1.value; ob.leftmost=ob1.leftmost; ob.rightmost=ob1.rightmost;
             }
             else{
                ob.freq=ob1.freq+ob2.freq; ob.value=ob2.value; ob.leftmost=ob1.leftmost; ob.rightmost=ob2.rightmost;
             }
        }
        else if(ob1.freq==ob2.freq){
            if(ob1.rightmost==ob2.leftmost && ob2.leftmost==ob2.value){
              int cont=0;
              for(int k=tmp1-1;k>=i;k--){
                if(input[k]!=ob2.value){ break; }
                cont++;
              }
              ob.freq=ob2.freq+cont; ob.value=ob2.value; ob.leftmost=ob1.leftmost; ob.rightmost=ob2.rightmost;
            }
            else if(ob1.rightmost==ob2.leftmost && ob2.leftmost==ob1.value){
              int cont=0;
              for(int k=tmp1;k<=j;k++){
                if(input[k]!=ob1.value){ break; }
                cont++;
              }
              ob.freq=ob1.freq+cont; ob.value=ob1.value; ob.leftmost=ob1.leftmost; ob.rightmost=ob2.rightmost;
            }
            else{
                ob.freq=ob2.freq; ob.value=ob2.value; ob.leftmost=ob1.leftmost; ob.rightmost=ob2.rightmost;
            }
        }

        else if(ob1.freq<ob2.freq){
            if(ob1.rightmost==ob2.leftmost && ob2.leftmost==ob1.value){
                int cont=0;
                for(int k=tmp1;k<=j;k++){
                if(input[k]!=ob1.value){ break; }
                cont++;
              }
              if((ob1.freq+cont)>ob2.freq){
                ob.freq=ob1.freq+cont; ob.value=ob1.value; ob.leftmost=ob1.leftmost; ob.rightmost=ob2.rightmost;
              }

        else{
                ob.freq=ob2.freq; ob.value=ob2.value; ob.leftmost=ob1.leftmost; ob.rightmost=ob2.rightmost;
            }
          }
          else if(ob1.rightmost==ob2.leftmost && ob2.leftmost==ob2.value){
                int cont=0;
                for(int k=tmp1-1;k>=i;k--){
                if(input[k]!=ob2.value){ break; }
                cont++;
              }
                ob.freq=ob2.freq+cont; ob.value=ob2.value; ob.leftmost=ob1.leftmost; ob.rightmost=ob2.rightmost;
             }

          else{
                ob.freq=ob2.freq; ob.value=ob2.value; ob.leftmost=ob1.leftmost; ob.rightmost=ob2.rightmost;
            }
        }
        else if(ob1.freq>ob2.freq){
            if(ob1.rightmost==ob2.leftmost && ob2.leftmost==ob2.value){
                int cont=0;
                for(int k=tmp1-1;k>=i;k--){
                if(input[k]!=ob2.value){ break; }
                cont++;
              }
              if(ob2.freq+cont>ob1.freq){
                ob.freq=ob2.freq+cont; ob.value=ob2.value; ob.leftmost=ob1.leftmost; ob.rightmost=ob2.rightmost;
              }
              else{
            ob.freq=ob1.freq; ob.value=ob1.value; ob.leftmost=ob1.leftmost; ob.rightmost=ob2.rightmost;
            }
            }

            else if(ob1.rightmost==ob2.leftmost && ob2.leftmost==ob1.value){
                int cont=0;
                for(int k=tmp1;k<=j;k++){
                if(input[k]!=ob1.value){ break; }
                cont++;
              }
              ob.freq=ob1.freq+cont; ob.value=ob1.value; ob.leftmost=ob1.leftmost; ob.rightmost=ob2.rightmost;

            }

            else{
            ob.freq=ob1.freq; ob.value=ob1.value; ob.leftmost=ob1.leftmost; ob.rightmost=ob2.rightmost;
            }
        }
        if(flag==2){
            tst1=tst1; tst2=tmp2;
            flag=1;
        }
        return ob;
    }

}


int main()
{
    ifstream in; ofstream out;
    in.open("input.txt");
    out.open("out.txt");
    int n,q,a,b;
    while(1){
    //scanf("%d",&n);
    in>>n;
    if(n==0){ break; }
    //scanf("%d",&q);
    in>>q;
    tst1=0; tst2=0; tmp1=0; tmp2=0;
    for(int i=1;i<=n;i++){
        //scanf("%d",&input[i]);
        in>>input[i];
    }
    make_tree(1,1,n);
    for(int i=0;i<q;i++){
         //scanf("%d%d",&a,&b);
         in>>a>>b;
         flag=0;
         node ob=query(1,1,n,a,b);
         //printf("%d\n",ob.freq);
         out<<ob.freq<<endl;
       }
    }
    in.close(); out.close();
    return 0;
}

