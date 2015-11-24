//
//  main.c
//  differentiation.c
//
//  Created by wei on 15/2/7.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "stdlib.h"

FILE *fp;

float delta_h(float x, float h){
    double result = (sin(x + h)-sin(x))/h;
    return result;
}

int main(int argc, const char * argv[]) {
    float input, x[3];
    double i;
    
    input = atof(argv[1]);
    
    fp = fopen("result.txt", "w");
    
    for (i = 0.1; i<10; i = i + 0.5) {
        x[0] = cos(input);
        x[1] = delta_h(input, i);
        x[2] = x[1] - x[0];
        printf("%f", x[1]);
        fprintf(fp, "%f %f %f\n", x[0],x[1], x[2]);
    }
    
    fclose(fp);
    return 0;
}
