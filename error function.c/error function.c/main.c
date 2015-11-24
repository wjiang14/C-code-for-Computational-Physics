//
//  main.c
//  error function.c
//
//  Created by wei on 15/4/15.
//  Copyright (c) 2015年 wei. All rights reserved.
//

//
//  main.c
//  numerical_integral3.c
//
//  Created by wei on 15/3/26.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <time.h>


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
    return q;
}

double erf(double x){
    return 2/sqrt(3.1415926) *exp(-pow(x,2));
}


int main(int argc, const char * argv[]) {
    double a = 0.0;
    double b = -5.0;
    double tol = 1e-7;
    double ans;
    int neval = 1000;
    
    FILE *fp;
    fp = fopen( "output.txt", "w" );
    clock_t start, finish;
    double  duration;
    /* duration of program */
    start = clock();
    
    double interval = 0.0;
    while (b + interval < 5) {
        ans = trap(erf, a, b + interval, tol, &neval);
        printf("%e %e\n", b+interval, ans);
        fprintf( fp, "%e %e\n", b+interval, ans);
        interval = interval + 1e-5;
    }
    
    finish = clock();
    fclose( fp );
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    
}