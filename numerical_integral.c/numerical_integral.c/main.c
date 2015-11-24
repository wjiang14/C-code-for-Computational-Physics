//
//  main.c
//  numerical_integral.c
//
//  Created by wei on 15/3/17.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>
#include <math.h>

FILE *fp;

double trap( double (*func)(double x), double a, double b, double h){
    int i;
    double final = 0, x0, x1 = 0;
    
    x0 = func(a) + func(b);
    for (i = 1; i < (b - a)/h; i++) {
        x1 = x1 + func(a + i*h);
        }
    final = (h/2)*(x0 + 2*x1);
    printf("%e\n", final);
    return final;
}

double myfun(double x){
    return exp(x);
}


int main(int argc, const char * argv[]) {
    int i;
    double a = 0.0;
    double b = 1.0;
    double ans;
    
    double h[9] = {0.2,0.125,0.1,0.0625,0.05,0.04,0.02,0.01,0.005};
    
    fp = fopen("exp(x).txt", "w");
    for (i = 0; i < 9; i++) {
        ans = fabs(trap(myfun, a, b, h[i]) - 1.71828);
        fprintf(fp, "%f %e\n", h[i], ans);
    }
    
    fclose(fp);
}
