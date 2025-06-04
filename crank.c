/*Name-
  roll-
  
*/



#include<stdio.h>
#include<math.h>
#define pi 3.14159
float x[100];

void TDMA(float a[100],float b[100],float c[100],float d[100],int m)
{ 
    int i;
    for(i=2;i<=m-1;i++)
    {
       b[i]=b[i]-(a[i]*c[i-1])/b[i-1];
       d[i]=d[i]-(a[i]*d[i-1])/b[i-1];
    }
    x[m-1]=d[m-1]/b[m-1];
    for(i=m-2;i>=1;i--)
    {
       x[i]=(d[i]-c[i]*x[i+1])/b[i];
    }
}

int main()
{
     int i,j,m,n;
     float k,r,dx,dt,u[100][100],a[100],b[100],c[100],d[100],exact;
     dx=0.25;
     k=1;
     m=1/dx;
    // m=m+1;
     //r=1;
    // dt=(r*dx*dx)/k;
    dt=0.0625;
     n=0.25/dt;
     r=k*dt/(dx*dx);
     for(i=1;i<=m-1;i++)
     {
       // u[i][0]=sin(pi*i*dx);
        u[i][0]=2*i*dx;
     }
     for(j=0;j<=n;j++)
     {
        u[0][j]=0.0;
        u[m][j]=0.0;
     }
     for(j=0;j<n;j++)
     {
        for(i=1;i<=m-1;i++)
        {
           a[i]=-r;
           b[i]=2*(1+r);
           c[i]=-r;
           d[i]=r*u[i-1][j]+2*(1-r)*u[0][j]+r*u[i+1][j];
        }
        d[1]=d[1]-a[1]*u[0][j];
        d[m-1]=d[m-1]-c[m-1]*u[m][j];
        TDMA(a,b,c,d,m);
        for(i=1;i<=m-1;i++)
        {
           u[i][j+1]=x[i];
        }
     }
     for(j=0;j<=n;j++)
     {
        printf("At time t=%f\n",j*dt);
        for(i=0;i<=m;i++)
        { 
           //exact=exp(-pi*pi*j*dt)*sin(pi*i*dx);
          // printf("%f %f %f\n",i*dx,u[i][j],exact);
           printf("%f %f\n",i*dx,u[i][j]);
        }
        printf("\n");
     
     }
     printf("The required solution u(1/2,1/8)=%f\n",u[2][2]);
     
     return 0;
}

/*
At time t=0.000000
0.000000 0.000000
0.250000 0.500000
0.500000 1.000000
0.750000 1.500000
1.000000 0.000000

At time t=0.062500
0.000000 0.000000
0.250000 0.428571
0.500000 0.714286
0.750000 0.428571
1.000000 0.000000

At time t=0.125000
0.000000 0.000000
0.250000 0.265306
0.500000 0.346939
0.750000 0.265306
1.000000 0.000000

At time t=0.187500
0.000000 0.000000
0.250000 0.137026
0.500000 0.201166
0.750000 0.137026
1.000000 0.000000

At time t=0.250000
0.000000 0.000000
0.250000 0.077051
0.500000 0.107039
0.750000 0.077051
1.000000 0.000000

The required solution u(1/2,1/8)=0.346939

*/


     
    
