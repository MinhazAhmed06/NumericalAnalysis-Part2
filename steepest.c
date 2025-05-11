/*
    NAME :- ANIRBAN CHATTERJEE
    ROLL NO :- 002220603012
    
PROBLEM :-  Use steepest decent method with   x^0 = (0,0,0)^T to find the approximation solution of non linear system 
            3x_1-cos(x_1 x_2) -0.5=0
            (x_1)^2-81((x_2)+0.1)^2+sin(x_3)+1.06=0
            e^(-x_2 x_2) +20x_3 +(10pi-3)/3 =0
            Take epsilon=0.1
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 3
#define Tol 0.01
#define Max_iter 100
double f1_val( double x[N] )// computing f1 = 3x1-cos(x2x3)-0.5
{
double r;
r= 3.0*x[0] - cos(x[1]*x[2])-0.5;
return r;
}
double f2_val(double x[N])// computing f2 = x1^2 -81(.1+x2)^2+sin(x3)+1.06
{
double r;
r= pow(x[0],2) -81.0*pow((x[1]+0.1),2)+sin(x[2])+1.06;
return r;
}
double f3_val( double x[N])// computing f3 = e^-(x1x2)+20x3+(10p-3)/3
{
double r ;
r= exp(-(x[0]*x[1]))+20.0*x[2]+(10.0*M_PI-3.0)/3.0;
return r;
}
double g_val( double x[N]) // computing g = f1^2 + f2^2 + f3^2
{
double r;
r = pow(f1_val(x),2)+pow(f2_val(x),2)+pow(f3_val(x),2);
return r;
}
double g_x1_val( double x[N])// computing del_g/del_x1
{ double r;
r= 2*(3*f1_val(x)+2*x[0]*f2_val(x)-x[1]*exp(-(x[0]*x[1]))*f3_val(x));
return r;
}
double g_x2_val( double x[N])// computing del_g/del_x2
{
double r;
r= 2*(x[2]*sin(x[1]*x[2])*f1_val(x)-2*81*(x[1]+0.1)*f2_val(x)-x[0]*exp(-(x[0]*x[1]))*f3_val(x));
return r;
}
double g_x3_val( double x[N])// computing del_g/del_x3
{ double r;
r= 2*(x[1]*sin(x[1]*x[2])*f1_val(x)+cos(x[2])*f2_val(x)+20*f3_val(x));
return r;
}
void g_gradient( double g_grad[N] , double x[N])// computing grad.g
{
double r1,r2,r3;g_grad[0] = g_x1_val(x);
g_grad[1] = g_x2_val(x);
g_grad[2]= g_x3_val(x);
}
double diff_norm(double x[N] , double y[N])// computing || x_(n+1)- x_(n)||
{
double r= 0.0;
for(int i=0 ; i<N;i++)
{
r+= pow((x[i]-y[i]),2);
}
return sqrt(r);
}
void x_next( double x[N] , double x_new[N] , double g_grad[N] , double alpha) // computing x_(n+1)
{
for(int i= 0 ; i<N ; i++)
{
x_new[i] = x[i]-alpha*g_grad[i] ;
}
}
int main()
{
int iter = 0;
double x[N],x_new[N],x_prev[N] ,g_grad[N];
for(int i= 0 ; i<N ;i++)
{
x[i]= 0.0;
}// setting initial solution {0,0,0}
printf("\n \t'n'\t\tx1\t\tx2\t\tx3 \n");
printf("\n \t0\t\t0\t\t0\t\t0 \n");
do{
double alpha = 1.0;
g_gradient(g_grad,x);
do{
x_next(x,x_new,g_grad,alpha);
if(g_val(x_new)>g_val(x))
alpha/=2;
}while(g_val(x_new)>g_val(x)); // the loop that ensures that alpha is chosen s.t. g(x_n+1)< g(
for(int i=0;i<N;i++)
{
x_prev[i] = x[i];
x[i]=x_new[i];
}
iter++;
printf("\n \t%d\t%.6f\t%.6f\t%.6f \n",iter,x[0],x[1],x[2]);
}while(iter<Max_iter && diff_norm(x,x_prev)>Tol);
return 0;
}
/*
OUTPUT :-

	'n'		x1		x2		x3 

 	0		0		0		0 

 	1	0.017578	0.015820	-0.819100 

 	2	0.034276	-0.039992	-0.355340 

 	3	0.050008	-0.023559	-0.619898 

 	4	0.066001	-0.023584	-0.469550 

 	5	0.081087	-0.016615	-0.554608 

 	6	0.095869	-0.018062	-0.506185 

 	7	0.110021	-0.015851	-0.533669 

 	8	0.137483	-0.017146	-0.502406 

 	9	0.150154	-0.014768	-0.535846 

 	10	0.162486	-0.015815	-0.516828 

 	11	0.186154	-0.013731	-0.538513 

 	12	0.197233	-0.015110	-0.515339 

 	13	0.218432	-0.012476	-0.541769 

 	14	0.228397	-0.014372	-0.513496 

 	15	0.237885	-0.012735	-0.529631 

 	16	0.256347	-0.013578	-0.511219 

 	17	0.264836	-0.011613	-0.530942 

 	18	0.273128	-0.012275	-0.519679 

 	19	0.289009	-0.010491	-0.532554 

 	20	0.296464	-0.011444	-0.518755 

 	21	0.310687	-0.009334	-0.534538 

 	22	0.317396	-0.010679	-0.517609 

 	23	0.323762	-0.009418	-0.527300 

 	24	0.336173	-0.009952	-0.516191 

 	25	0.341867	-0.008467	-0.528105 

 	26	0.353022	-0.009366	-0.514439 

 	27	0.358107	-0.007552	-0.529103 

 	28	0.363123	-0.008221	-0.520685 
 	all result correct upto 6 decimal places
*/
