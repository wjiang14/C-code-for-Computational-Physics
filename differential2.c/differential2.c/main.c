//
//  main.c
//  differential2.c
//
//  Created by wei on 15/4/3.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "stdlib.h"

FILE *fp;

double delta_h2(double (*func)(double x), double x, double h){
    double result2 = (func(x + h) - func(x - h))/(2*h);
    return result2;
}

double myfun(double x){
    return exp(x);
}

int main(int argc, const char * argv[]) {
    
    
    fp = fopen("result_x3.txt", "w");
    double x = 2.0, h[6] = {0.05, 0.02, 0.01, 0.005, 0.002, 0.0015};

    for (int i = 0; i < 6; i++) {
        double q = fabs((4*delta_h2(myfun, x, h[i]/2) - delta_h2(myfun, x, h[i]))/3 - exp(x));
        fprintf(fp, "%e %e\n", h[i], q);
        printf("%e %e \n", h[i], q);
    }
    fclose(fp);
    
    return 0;
}
