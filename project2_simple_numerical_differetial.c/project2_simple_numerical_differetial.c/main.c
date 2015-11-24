//
//  main.c
//  project2_simple_numerical_differetial.c
//
//  Created by wei on 15/2/23.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "stdlib.h"

FILE *fp;

double delta_h1(double (*func)(double x), double x, double h){
    double result1 = (func(x + h) - func(x))/h;
    return result1;
}

double delta_h2(double (*func)(double x), double x, double h){
    double result2 = (func(x + h) - func(x - h))/(2*h);
    return result2;
}

double delta_h5(double (*func)(double x), double x, double h){
    double result5 = (-func(x + 2*h) + 8*func(x + h) - 8*func(x - h) + func(x - 2*h))/(12*h);
    return result5;
}

double myfun(double x){
    return pow(x, 3);
}

int main(int argc, const char * argv[]) {
    float x[3];
    float h[14] = {5e-15, 3e-15, 2e-15, 1e-15, 1e-10, 1e-5, 0.01, 0.02, 0.03, 0.04, 0.05, 0.07, 0.08, 0.1};

    
    fp = fopen("result_x3.txt", "w");
    for (int i = 0; i < 14; i++) {
        x[0] = fabs(delta_h1(myfun, 2, h[i]) - 12);
        x[1] = fabs(delta_h2(myfun, 2, h[i]) - 12);
        x[2] = fabs(delta_h5(myfun, 2, h[i]) - 12);
        fprintf(fp, "%f %f %f %f\n", h[i], x[0],x[1],x[2]);
        printf("%e %e %e %e\n", h[i], x[0],x[1],x[2]);
    }
    fclose(fp);
    
    return 0;
}
