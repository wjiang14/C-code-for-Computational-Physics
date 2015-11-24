//
//  main.c
//  numerical differentiation_x.c
//
//  Created by wei on 15/2/12.
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
    float h, x[3], coo;
    
    fp = fopen("result.txt", "w");
    
    for (h = 1; h < 3.14159; h = h + 0.05) {
        for (coo = 0; coo < 3.14; coo = coo + 1) {
            x[0] = cos(coo);
            x[1] = delta_h(coo, h);
            x[2] = x[1] - x[0];
            printf("%f", x[2]);
            fprintf(fp, "%f,%f,%f,", coo, h, x[2]);
        }
        
    }

    fprintf(fp, "%f,%f,%f", coo, h, x[2]);
    
    fclose(fp);
    return 0;
}
