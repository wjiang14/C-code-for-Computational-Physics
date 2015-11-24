//
//  main.c
//  project2_2nd.c
//
//  Created by wei on 15/3/9.
//  Copyright (c) 2015年 wei. All rights reserved.
//


#include <stdio.h>
#include <math.h>
#include "stdlib.h"

FILE *fp;

double delta_h_x3(float x, float h){
    double result = (pow(x + h, 3) - pow(x, 3))/h;
    return result;
}

double delta_h_2point_x3(float x, float h){
    double result = (pow(x + h, 3) - pow(x - h, 3))/(2*h);
    return result;
}

int main(int argc, const char * argv[]) {
    double h, x[2];
    
    fp = fopen("result_x2.txt", "w");
    for (h = 0.01; h < 1; h = h + 0.005) {
        x[0] = delta_h_x3(1, h) - 3*1;
        x[1] = 2*delta_h_x3(1, h/2) - delta_h_x3(1, h) - 3*1;
        fprintf(fp, "%f %e %e\n", h, x[0],x[1]);
    }
    fclose(fp);
    
    fp = fopen("result_2point_x2.txt", "w");
    for (h = 0.01; h < 1; h = h + 0.005) {
        x[0] = delta_h_2point_x3(1, h) - 3*1;
        x[1] = (4*delta_h_2point_x3(1, h/2) - delta_h_2point_x3(1, h))/3 - 3*1;
        fprintf(fp, "%f %e %e\n", h, x[0],x[1]);
    }
    fclose(fp);

    
    return 0;
}
