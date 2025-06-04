
/* name : 
roll : 
problem statement : write a C programme to solve the following boundary value problem
U_tt = U_xx ,0<x,4 , t>0
subject to the following initial and boundary conditions
u(x,0)=4x-x^2 , del(u)/del(t)(x,0)=0,0<x<4
u(0,t)=0=u(d,t)=0,t>=0
integrate upto three time levels by taking h=1 , k=0.5*/



#include<stdio.h>
#include<math.h>

#define N 4
#define M 3
#define h 1.0
#define k 0.5
#define lambda (k/h)
#define L2 ( lambda*lambda)


int main()

{ double u[N+1][M+1];
  for(int i=0;i<=N;i++)
  {  double x=i*h;
  u[i][0]=4*x-x*x;}
  
  for(int i=1;i<N;i++)
  {  u[i][1]=u[i][0]+0.5*L2*(u[i+1][0]-2*u[i][0]+u[i-1][0]);}
  
  u[0][0]=u[N][0]=0.0;
  u[0][1]=u[N][1]=0.0;
  
  for(int n=1;n<M;n++)
  {  for(int i=1;i<N;i++)
  {  u[i][n+1]=2*u[i][n]-u[i][n-1]+L2*(u[i+1][n]-2*u[i][n]+u[i-1][n]);}
  u[0][n+1]=u[N][n+1]=0;}
  
  printf(" Time step Results (correct upto 6 decimals):\n\n");
  printf(" \t t \t x=0 \t x=1 \t x=2 \t x=3 \t  x=4 \n");
  for(int n=0;n<=M;n++)
  {  printf("\t %0.2f",n*k);
     for(int i=0;i<=N;i++)
     {  printf(" %0.6f",u[i][n]);}
     printf("\n");}
     return 0;}
     
     ***************** OUTPUT *****************
     
     ime step Results (correct upto 6 decimals):

 	 t 	 x=0 	 x=1 	 x=2 	 x=3 	  x=4 
	 0.00 0.000000 3.000000 4.000000 3.000000 0.000000
	 0.50 0.000000 2.750000 3.750000 2.750000 0.000000
	 1.00 0.000000 2.062500 3.000000 2.062500 0.000000
	 1.50 0.000000 1.093750 1.781250 1.093750 0.000000

  
