#include<bits/stdc++.h>

using namespace std;

int main()
{
    int bcg,bgc,cbg,cgb,gbc,gcb,b1,g1,c1,b2,g2,c2,b3,g3,c3;

    while(scanf("%d",&b1)!=EOF){
        scanf("%d%d%d%d%d%d%d%d",&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3);

        bcg=(b2+b3) + (c1+c3) + (g1+g2);
        bgc=(b2+b3) + (g1+g3) + (c1+c2);
        cbg=(c2+c3) + (b1+b3) + (g1+g2);
        cgb=(c2+c3) + (g1+g3) + (b1+b2);
        gbc=(g2+g3) + (b1+b3) + (c1+c2);
        gcb=(g2+g3) + (c1+c3) + (b1+b2);

        if(bcg<=bgc && bcg<=cbg && bcg<=cgb && bcg<=gbc && bcg<=gcb){
            printf("BCG %d\n",bcg);
        }
        else if(bgc<=bcg && bgc<=cbg && bgc<=cgb && bgc<=gbc && bgc<=gcb){
            printf("BGC %d\n",bgc);
        }
        else if(cbg<=bgc && cbg<=bcg && cbg<=cgb && cbg<=gbc && cbg<=gcb){
            printf("CBG %d\n",cbg);
        }
        else if(cgb<=bgc && cgb<=bcg && cgb<=cbg && cgb<=gbc && cgb<=gcb){
            printf("CGB %d\n",cgb);
        }
        else if(gbc<=bgc && gbc<=bcg && gbc<=cgb && gbc<=cbg && gbc<=gcb){
            printf("GBC %d\n",gbc);
        }
        else{
            printf("GCB %d\n",gcb);
        }
    }
    return 0;
}
