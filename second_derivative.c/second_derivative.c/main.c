//
//  main.c
//  second_derivative.c
//
//  Created by wei on 15/3/9.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "stdlib.h"

FILE *fp;

double delta_2derivative_h_sin(float x, float h){
    double result = (sin(0.5+h) + sin(0.5-h) - 2*sin(0.5))/pow(h, 2);
    return result;
}


int main(int argc, const char * argv[]) {
    double h, x;
    
    fp = fopen("result_sin(0.5).txt", "w");
    for (h = 0.001; h < 0.1; h = h + 0.005) {
        x = delta_2derivative_h_sin(0.5, h) + sin(0.5);
        fprintf(fp, "%f %e\n", h, x);
    }
    fclose(fp);
    
    return 0;
}
