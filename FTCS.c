


/* Name : 
Roll Number = 
Problem Statement : Solve Ut=Uxx , 0<x<1,t>0,
Where u(0,t)=u(1,t)=0,t>0 and u(x,0)=sin(pi*x), by taking h=1/3 , k=1/36 . */


#include<stdio.h>
#include<math.h>
#define N 3
#define M 5

int main()
{ double u[N+1][M+1];
double h= 1/3.0;
double k=1/36.0;
double r= k/(h*h);

for (int i=0;i<=N;i++)
{ u[i][0]=sin(M_PI*i*h);}

for(int n=0;n<=M;n++)
{  u[0][n]=0.0;
u[N][n]=0.0;}

for(int n=0;n<M;n++)
{ for(int i=1;i<N;i++)
{ u[i][n+1]=u[i][n]+r*(u[i+1][n]-2*u[i][n]+u[i-1][n]);}}

printf("Time\tx=0\t\tx=1/3\t\tx=2/3\t\tx=1\n");
for(int n=0;n<=M;n++)
{ if(n==0)
    printf("t=0\t");
  else 
    printf("t=%d/36\t",n);
  for(int i=0;i<=N;i++)
  {  printf("%.6f\t",u[i][n]);}
  printf("\n");}
  return 0;}
  
  
  ***********OUTPUT*********
  
  Time	x=0		x=1/3		x=2/3		x=1
t=0	0.000000	0.866025	0.866025	0.000000	
t=1/36	0.000000	0.649519	0.649519	0.000000	
t=2/36	0.000000	0.487139	0.487139	0.000000	
t=3/36	0.000000	0.365354	0.365354	0.000000	
t=4/36	0.000000	0.274016	0.274016	0.000000	
t=5/36	0.000000	0.205512	0.205512	0.000000	

