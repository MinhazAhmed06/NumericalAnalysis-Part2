


/*
Name : 
Roll number : 
 problem statement : solve f(x) -2 .[integration from 0 to x.. (cos (x-t)).f(t)dt] = e^x , 
by taking f(0)=1 , h=0.1 , at x = 0.1,...,1.0 .*/


#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define h 0.1
#define x_end 1

double phi(double x)
{ double r=exp(x);;
return r;}

double ker(double x, double t)
{ double r= 2*cos(x-t);
return r;}

int main()

{ int i,j,k;
int n= (int) ceil(x_end/h);
double f[n+1],w[n+1],x[n+1],t[n+1];
f[0]=1.0;
for(i=1;i<=n;i++)
{ double sum=0;
  x[i]=i*h;
  t[i]=x[i];
  w[0]=w[i]=h/2;
  for(j=0;j<i;j++)
  {
    for(k=1;k<=j;k++)
     {w[k]=h;};
    x[j]=j*h;
    t[j]=x[j];
    sum+= w[j]*f[j]*ker(x[j],t[j]);};
    f[i]=(phi(x[i])+sum)/(1-w[i]*ker(x[i],t[i]));
    printf("\n The value of f[%f] is : %f\n",x[i],f[i]);};
return 0;}


**************OUTPUT*********

The value of f[0.100000] is : 1.339079

 The value of f[0.200000] is : 1.765798

 The value of f[0.300000] is : 2.300927

 The value of f[0.400000] is : 2.969984

 The value of f[0.500000] is : 3.804310

 The value of f[0.600000] is : 4.842376

 The value of f[0.700000] is : 6.131386

 The value of f[0.800000] is : 7.729237

 The value of f[0.900000] is : 9.706914

 The value of f[1.000000] is : 12.151427

( Correct upto 6 decimal places)

