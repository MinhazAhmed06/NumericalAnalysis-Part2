
/* name : 
Roll . 
problem statement : write a c programme to solve the following p.d.e. 
U_xx+U_yy=1, [x]<1,[y]<1
with u=0 on [x]=1 ,[y]=1 , using a suitable finite difference schame and find u(0,0) by taking 
h=k=1/2.

[.] denotes mod function */ 


#include<stdio.h>
#include<math.h>

#define N 4
#define Tol 1e-4
#define MAX_ITER 1000
#define H 0.25

int main()
{   
 double u[N+1][N+1];
 for(int i=0;i<=N;i++)
 {  u[i][0]=0.0;
    u[0][i]=0.0;
    u[i][N]= 0.0;
    u[N][i]= 0.0;}
    
 for(int i=1;i<N;i++)
 {  for(int j=1;j<N;j++)
    {  u[i][j]=0.0;}}
    
 double diff, new_value;
 int iter =0;
 do{
 diff=0.0;
 for(int i=1;i<N;i++)
 {  for(int j=1;j<N;j++)
    {  new_value=0.25*(u[i+1][j]+u[i-1][j]+u[i][j+1]+u[i][j-1]-H);
      diff+=fabs(new_value-u[i][j]);
      u[i][j]=new_value;}}
      iter++;} while(diff>Tol && iter< MAX_ITER);
      
 
 printf(" Solution at interior points( correct upto 6 decimal places ):\n");
 printf(" \t x  \t y  \t u \n");
 for(int i=1;i<N;i++)
 {  for(int j=1;j<N;j++)
    {  printf(" \t %0.2f \t %0.2f   %0.6f\n",(i-2)*0.5,(j-2)*0.5,u[i][j]);}}
 
    
printf(" Approximate value of u(0,0) ( correct upto 6 decimal places ): %0.6f\n",u[2][2]);
    return 0;}
    
    
    *******************OUTPUT*******************
    
    Solution at interior points( correct upto 6 decimal places ):
 	 x  	 y  	 u 
 	 -0.50 	 -0.50   -0.171863
 	 -0.50 	 0.00   -0.218738
 	 -0.50 	 0.50   -0.171869
 	 0.00 	 -0.50   -0.218738
 	 0.00 	 0.00   -0.281238
 	 0.00 	 0.50   -0.218744
 	 0.50 	 -0.50   -0.171869
 	 0.50 	 0.00   -0.218744
 	 0.50 	 0.50   -0.171872
 Approximate value of u(0,0) ( correct upto 6 decimal places ): -0.281238

    
      

