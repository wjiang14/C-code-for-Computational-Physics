//
//  main.c
//  numerical_integral.c
//
//  Created by wei on 15/3/17.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>
#include <math.h>


double trap( double (*func)(double x), double a, double b, double vol, int *neval){
    int i, n, step;
    double h, xk, p, ep, y, temp;
    
    n = 1;
    step = *neval;
    i = 0;
    temp = 0;
    h = b - a;
    ep = vol + 1;
    y = h*(func(a) + func(b))/2.0;
    int counter = 2;
    
    while ((ep >= vol)&&counter < step) {
        p = 0.0;
        for (i = 0; i < n; i++) {
            xk = a + (i + 0.5)*h;
            p = p + func(xk);
            counter++;
        }
        y = (y + h*p)/2.0;
        ep = fabs(y-temp);
        temp = y;
        n = n + n;
        h = h/2.0;
        printf("%e, %d %d %e %e\n",h ,counter, n, ep, y);
    }
    return y;
}

double myfun(double x){
    return exp(-(x*x));
}

int main(int argc, const char * argv[]) {
    double vol = 1e-7;
    double a = 0.0;
    double b = 1.0;
    double ans;
    int neval = 10000;
    
    ans = trap(myfun, a, b, vol, &neval);

}
