#include<iostream>
#include<stack>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
    int n=0;
    scanf("%d",&n);
    getchar();
    stack<char>stk;
    for(int i=0;i<n;i++){
        int ck=1;
        char ch;
        stk=stack<char>();
        while ((ch = getchar()) != '\n'){
                if(ch==' '){continue;}
                if(ch=='(' || ch=='['){
                    stk.push(ch);
                   }
                else{
                    if(stk.empty()){
                       ck=0;
                    }
                    else if(stk.top()=='(' && ch!=')'){
                        ck=0;

                    }
                    else if(stk.top()=='[' && ch!=']'){
                        ck=0;
                    }
                    else {
                        stk.pop();
                    }
                }
        }
        if(ck!=0){
        if(stk.empty()){ck=1;}
        else{ck=0;}
        }

        if(ck==1){
            cout<<"Yes"<<endl;
        }
        else{cout<<"No"<<endl;}
    }
}

