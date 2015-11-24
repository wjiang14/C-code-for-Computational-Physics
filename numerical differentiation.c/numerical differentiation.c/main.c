//
//  main.c
//  numerical differentiation.c
//
//  Created by wei on 15/2/8.
//  Copyright (c) 2015年 wei. All rights reserved.
//
#include <stdio.h>
#include <math.h>
#include "stdlib.h"

FILE *fp;

float delta_h(float x, float h){
    float result = (sin(x + h)-sin(x))/h;
    return result;
}

int main(int argc, const char * argv[]) {
    float h, x[3];
    float i;
    
    h = atof(argv[1]);
    
    fp = fopen("result.txt", "w");
    
    for (i = 0.0; i < 3.14159; i = i + 0.05) {
        x[0] = cos(i);
        x[1] = delta_h(i, h);
        x[2] = x[1] - x[0];
        printf("%f", x[1]);
        fprintf(fp, "%f,%f,%f,", x[0],x[1], x[2]);
    }
    
    fclose(fp);
    return 0;
}