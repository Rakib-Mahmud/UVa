#include<bits/stdc++.h>
using namespace std;

map<char,char>keyboard;


int main()
{
    char frst_row[]={'=','-','0','9','8','7','6','5','4','3','2','1','`'};
    for(int i=0;i<12;i++){
        keyboard[frst_row[i]]=frst_row[i+1];
    }

    char scnd_row[]={'\\',']','[','P','O','I','U','Y','T','R','E','W','Q'};
    for(int i=0;i<12;i++){
        keyboard[scnd_row[i]]=scnd_row[i+1];
    }

    char thrd_row[]={'\'',';','L','K','J','H','G','F','D','S','A'};
    for(int i=0;i<10;i++){
        keyboard[thrd_row[i]]=thrd_row[i+1];
    }

    char frth_row[]={'/','.',',','M','N','B','V','C','X','Z'};
    for(int i=0;i<9;i++){
        keyboard[frth_row[i]]=frth_row[i+1];
    }

    int a;
    char c1,c2,input[1000];

    while(gets(input)){
    a=strlen(input);

    for(int i=0;i<a;i++){
        c1=input[i];
        if(c1==' '){
            printf("%c",c1);
        }
        else{
            c2=keyboard[c1];
            printf("%c",c2);
        }
    }
    printf("\n");

  }

return 0;
}
