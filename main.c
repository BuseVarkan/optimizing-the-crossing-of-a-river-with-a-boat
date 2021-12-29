#include <stdio.h>
#include <math.h>
#define MAX 110
int main()
{
    double dt,v,vy,vx;
    int n,k,i=0;
    double x_arr[MAX],cur_arr[MAX];
    double alfa[MAX];
    double x=0,t=0,R,temp;

    scanf("%lf %lf",&dt,&v);
    scanf(" %d",&n);
    for(k=0;k<(n+1);k++)
    {
        scanf(" %lf %lf",&x_arr[k],&cur_arr[k]);
    }

    alfa[0]=0;
    for(k=0;k<(n+1);k++)
    {
        alfa[k+1]=-alfa[k]+2*(cur_arr[k+1]-cur_arr[k])/(x_arr[k+1]-x_arr[k]);
    }

    R=x_arr[n];
    while(x<R)
    {
        for(k=0;k<(n+1);k++)
        {
            if(x==x_arr[k])
            {
                vy=cur_arr[k];
                temp=pow(v,2)-pow(vy,2);
                vx=sqrt(temp);
                x+=(dt*vx);
                t+=dt;
                break;
            }
            if((x<x_arr[k+1])&&(x>x_arr[k])&&(k+1<n+1))
            {
                i=k;
                vy=cur_arr[i]+alfa[i]*(x-x_arr[i])+(alfa[i+1]-alfa[i])*pow((x-x_arr[i]),2)/(2*(x_arr[i+1]-x_arr[i]));
                temp=pow(v,2)-pow(vy,2);
                vx=sqrt(temp);
                x+=(dt*vx);
                t+=dt;
                break;
            }
        }
    }
    printf("%lf",t);
    return 0;
}
