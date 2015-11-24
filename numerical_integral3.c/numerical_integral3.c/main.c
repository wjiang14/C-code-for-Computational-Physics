//
//  main.c
//  numerical_integral3.c
//
//  Created by wei on 15/3/26.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>
#include <math.h>


double trap( double (*func)(double x), double a,double b, double tol, int *neval)
{
    int m,n,k;
    double h,ep,p,xk,s,q,y[*neval];
    h = b-a;

    y[0]=h*(func(a)+func(b))/2.0;  //计算T`1`(h)=1/2(b-a)(f(a)+f(b));
    m = 1;
    n = 1;
    ep = tol+1;
    int counter = 2;
    while((ep >= tol)&&(m < *neval))
    {
        p=0.0;
        for(k=0; k<n; k++)
        {
            xk=a + (k + 0.5)*h;     //   n-1
            p = p + func(xk);  //∑f(xk+h/2),T
            counter++;
        }                       //   k=0
        p = (y[0] + h*p)/2.0;   //T`m`(h/2),calculate for the area
        s = 1.0;
        for(k=1; k<=m; k++)
        {
            s = 4.0*s;  // pow(4,m)
            q = (s*p-y[k-1])/(s-1.0);//[pow(4,m)T`m`(h/2)-T`m`(h)]/[pow(4,m)-1]
            y[k-1] = p;
            p=q;
        }
        ep=fabs(q-y[m-1]);  //accuracy
        m=m+1;
        y[m-1]=q;
        n=n+n;   //  2 4 8 16
        h=h/2.0;
    }
    printf("%e %d %d, %d, %e, %e\n",h, counter, n, m, ep, q);
    return q;
}
    
double myfun(double x){
    return exp(-(x*x));
}


int main(int argc, const char * argv[]) {
    double a = 0.0;
    double b = 1.0;
    double tol = 1e-7;
    double ans;
    int neval = 1000;
    
    ans = trap(myfun, a, b, tol, &neval);
    
}
