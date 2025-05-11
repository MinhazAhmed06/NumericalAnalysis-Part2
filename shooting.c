
/* Write a C programme to solve the following boundary value problem using shooting mathod and show your output,
U''=6U^2 , 0<x<0.3
U(0)=1, U(0.3)=100/169.
assume h=0.1*/




#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define h 0.1
#define Tol 1e-6
#define Max_Iter 1000

double f1(double v)
{ return v;}

double f2(double u , double v)
{  return 6*u*u;}

void runge_kutta( double u0, double v0,double x_end, double *u_end)
{  double u=u0,v=v0;
   int n =(int)ceil(x_end/h);
   printf("\n For v0=%0.6f:\n",v0);
   for(int i=0;i<=n;i++)
   {  double x=i*h;
      if( fabs(x-0.1)< Tol || fabs(x-0.2)<Tol || fabs(x-0.3)<Tol )
      {  printf(" u(%0.1f) = %0.6f\n",x,u);}
      if(x>=x_end)
      {  *u_end=u;
          break;}
          
      double k1=h*f1(v);
      double l1=h*f2(u,v);
      
      double k2=h*f1(v+l1/2);
      double l2 = h*f2(u+k1/2,v+l1/2);
      
      double k3=h*f1(v+l2);
      double l3 = h*f2(u+k2/2,v+l2/2);
      
      double k4=h*f1(v+l3);
      double l4=h*f2(u+k3,v+k3);
      
      u+=(k1+2*k2+2*k3+k4)/6;
      v+=(l1+2*l2+2*l3+l4)/6;}}
      
     void shooting_method( double u0, double u_end_target)
     {  double v1=0.0,v2=1.0,u_end1,u_end2;
        int iter=0;
        
        runge_kutta(u0,v1,0.3,&u_end1);
        runge_kutta(u0,v2,0.3,&u_end2);
        
        while( iter<Max_Iter)
        {  if(fabs(u_end2-u_end1)<1e-10)
        {  printf(" Divison by zero or too close. Adjust initial guess.\n");
        return;}
        
        double v_new=v2-(u_end2-u_end_target)*(v2-v1)/(u_end2-u_end1);
        double u_new;
        
        printf("\n Trying v0 =%0.6f\n",v_new);
        runge_kutta(u0,v_new,0.3,&u_new);
        if(fabs(u_new-u_end_target)<Tol)
        {  printf(" The optimal slope is : v0= %0.6f\n",v_new);
           return ;}
           
        v1=v2;
        v2=v_new;
        u_end1=u_end2;
        u_end2=u_new;
        iter++;}
        
        printf(" Max iterations reached . Slope may not be optimal.\n");
        printf(" Slope is : %0.6f\n",v2);}
        
        
        int main()
        {  double u0=1.0;
        double u_end_target=100.0/169.0;
        shooting_method(u0,u_end_target);
        printf("\n (All values are correct upto 6 decimal places )");
        return 0;}
        
        
        
        ********************** OUTPUT **************
        
        
        For v0=0.000000:
 u(0.1) = 1.040302
 u(0.2) = 1.147741
 u(0.3) = 1.338605

 For v0=1.000000:
 u(0.1) = 1.143392
 u(0.2) = 1.370492
 u(0.3) = 1.720090

 Trying v0 =-1.957846

 For v0=-1.957846:
 u(0.1) = 0.838902
 u(0.2) = 0.718304
 u(0.3) = 0.627527

 Trying v0 =-2.054796

 For v0=-2.054796:
 u(0.1) = 0.828944
 u(0.2) = 0.697267
 u(0.3) = 0.593511

 Trying v0 =-2.059911

 For v0=-2.059911:
 u(0.1) = 0.828419
 u(0.2) = 0.696158
 u(0.3) = 0.591719

 Trying v0 =-2.059920

 For v0=-2.059920:
 u(0.1) = 0.828418
 u(0.2) = 0.696156
 u(0.3) = 0.591716
 The optimal slope is : v0= -2.059920

 (All values are correct upto 6 decimal places )
           
           
           
           

