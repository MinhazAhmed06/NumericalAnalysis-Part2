
/* name :  
roll: 
problem statement : solve the integral equation by quadrature formula method 
f(x)- integratiion (0 to 1) (x+1) dt =(3/2)x-5/6*/


#include<stdio.h>
#include<math.h>

#define l 0.0
#define u 1.0
#define h 0.5



void Gauss_Elimination( int n , double a[n+1][n+1],double b[n+1], double x[n+1])
{  for(int i=0;i<=n-1;i++)
   {  for(int j=i+1;j<=n;j++)
      {  double m= a[j][i]/a[i][i];
         for(int k=i;k<=n;k++)
         {  a[j][k]-=m*a[i][k];}
         b[j]-=m*b[i];}}

x[n]=b[n]/a[n][n];
for(int i=n-1;i>=0;i--)
{  double sum =0;
   for(int j=i+1;j<=n;j++)
   {  sum+= a[i][j]*x[j];}
   x[i]=(b[i]-sum)/a[i][i];}}
   
   
   double ker(double x , double t)
   {  return x+t;}
   
   double phi( double x)
   {  return (3*x/2.0)-(5.0/6.0);}
   
   
   int main()
   {  int n = (int) ceil((u-l)/h);
    double w[n+1] , f[n+1][n+1] , b[n+1] , x[n+1],a[n+1][n+1];
    w[0]=w[n]=h/2.0;
    for(int i=1;i<n;i++)
    {  w[i]=h;}
    
    for(int i=0;i<=n;i++)
    {  for(int j=0;j<=n;j++)
       {  if(i==j)
          {  f[i][j]=1.0-w[i]*ker(l+i*h,l+i*h);}
          else
          {  f[i][j]=-w[j]*ker(l+j*h,l+i*h);}}}
          
          
    for(int i=0;i<=n;i++)
    {  b[i]=phi(l+i*h);}
    
    printf("\n Matrix F :\n");
    for(int i=0;i<=n;i++)
    {  for(int j=0;j<=n;j++)
       {  printf("%0.6f\t",f[i][j]);}
       printf("\n");}
       
       printf("\n The right hand vector\n");
          for(int i=0;i<=n;i++)
          {printf("%.6f\n",b[i]);}
          
          Gauss_Elimination(n,f,b,x);
          printf("\n The required f values are \n\n");
          printf("\t x \t f\n");
          for(int i=0;i<=n;i++)
          {  printf("\t %.2f \t %0.6f\n",i*h,x[i]);}
          printf("\n (All the values are correct upto 6 decimal places )");
          return 0;}
         
         
         ******************* OUTPUT *****************
         
         Matrix F :
1.000000	-0.250000	-0.250000	
-0.125000	0.500000	-0.375000	
-0.250000	-0.750000	0.500000	

 The right hand vector
-0.833333
-0.083333
0.666667

 The required f values are 
 
	 x 	 f
	 0.00 	 -1.166667
	 0.50 	 -0.833333
	 1.00 	 -0.500000

 (All the values are correct upto 6 decimal places )
          
