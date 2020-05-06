#include<bits/stdc++.h>

using namespace std;

struct point{
    double x,y;
};

int main()
{
    point input[50001],mid1,mid2,low,high;
    double dis1,dis2,res_x,min_dis1,res_time,mn_x,mx_x,mx_y,min_dis2,dis3,dis4;
    int n,in_mnx,in_mxx,in_mxy,c;
    while(1){
        mn_x=200001; mx_x=-200001; mx_y=-200001;  c=100;
        scanf("%d",&n);
        if(n==0){ break; }

        for(int i=0;i<n;i++){
            scanf("%lf%lf",&input[i].x,&input[i].y);
            if(input[i].x>mx_x){
                mx_x=input[i].x;
                in_mxx=i;
            }
            if(input[i].x<mn_x){
                mn_x=input[i].x;
                in_mnx=i;
            }
            if(fabs(input[i].y)>fabs(mx_y)){
                mx_y=input[i].y;
                in_mxy=i;
            }
        }
        low.x=input[in_mnx].x; low.y=input[in_mnx].y;
        high.x=input[in_mxx].x; high.y=input[in_mxx].y;
        while(c--){
            mid1.x=((low.x*2)+high.x)/3;
            mid1.y=((low.y*2)+high.y)/3;

            mid2.x=(low.x+(high.x*2))/3;
            mid2.y=(low.y+(high.y*2))/3;

            dis1=sqrt(pow((input[in_mnx].x-mid1.x),2)+pow((input[in_mnx].y-0),2));
            dis2=sqrt(pow((input[in_mxx].x-mid1.x),2)+pow((input[in_mxx].y-0),2));

            dis3=sqrt(pow((input[in_mnx].x-mid2.x),2)+pow((input[in_mnx].y-0),2));
            dis4=sqrt(pow((input[in_mxx].x-mid2.x),2)+pow((input[in_mxx].y-0),2));

            min_dis1=fabs(dis1-dis2);
            min_dis2=fabs(dis3-dis4);

            if(min_dis1==0 || min_dis2==0){
                    break;
            }

            if(min_dis1<=min_dis2){
                high.x=mid2.x;
                high.y=mid2.y;
                //cout<<min_dis1<<" "<<min_dis2<<endl;
            }
            else if(min_dis1>min_dis2){
                low.x=mid1.x;
                low.y=mid1.y;
                //cout<<min_dis1<<" "<<min_dis2<<endl;
            }


        }
        if(min_dis1<min_dis2){
            printf("%lf %lf\n",mid1.x,(dis1>dis2?dis1:dis2));
        }
        else{
            printf("%lf %lf\n",mid2.x,(dis3>dis4?dis3:dis4));
        }
        //cout<<(mid1.x+mid2.x)/2;
    }
    return 0;
}
