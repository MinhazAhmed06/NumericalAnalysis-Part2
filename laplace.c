/* name : 
Roll : 
problem statement : write a c programme to solve the following p.d.e. using finite difference scheme ,
U_xx+U_yy =0, 0<x,y<1,
u(x,0)=0,u(0,y)=0,u(x,1)10x,u(1,y)=10y
Find the approximate value at interior points */




#include<stdio.h>
#include<math.h>

#define N 4
#define Tol 1e-4
#define MAX_ITER 1000

int main()
{   
 double u[N+1][N+1];
 for(int i=0;i<=N;i++)
 {  u[i][0]=0.0;
    u[0][i]=0.0;
    u[i][N]= 10*(i*0.25);
    u[N][i]=10*(i*0.25);}
    
 for(int i=1;i<N;i++)
 {  for(int j=1;j<N;j++)
    {  u[i][j]=0.0;}}
    
 double diff, new_value;
 int iter =0;
 do{
 diff=0.0;
 for(int i=1;i<N;i++)
 {  for(int j=1;j<N;j++)
    {  new_value=0.25*(u[i+1][j]+u[i-1][j]+u[i][j+1]+u[i][j-1]);
      diff+=fabs(new_value-u[i][j]);
      u[i][j]=new_value;}}
      iter++;} while(diff>Tol && iter< MAX_ITER);
      
 printf(" Solution at interior points( correct upto 6 decimal places ):\n");
 printf(" \t x  \t y  \t u \n");
 for(int i=1;i<N;i++)
 {  for(int j=1;j<N;j++)
    {  printf(" \t %0.2f \t %0.2f   %0.6f\n",i*0.25,j*0.25,u[i][j]);}}
    return 0;}
   
   
   **************** OUTPUT ****************
  
    Solution at interior points( correct upto 6 decimal places ):
 	 x  	 y  	 u 
 	 0.25 	 0.25   0.624987
 	 0.25 	 0.50   1.249987
 	 0.25 	 0.75   1.874993
 	 0.50 	 0.25   1.249987
 	 0.50 	 0.50   2.499987
 	 0.50 	 0.75   3.749993
 	 0.75 	 0.25   1.874993
 	 0.75 	 0.50   3.749993
 	 0.75 	 0.75   5.624997

    
      

