//
//  main.c
//  radioactive_decay
//
//  Created by wei on 15/1/26.
//  Copyright (c) 2015年 wei. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    /* define viables */
    float t, tau, remain, lamada;
    FILE *fp;
    
    /* input parameter */
    tau = 5.0e4;
    lamada = log(2)/tau;
    
    /* create a new file alled output.txt */
    fp = fopen("output.txt", "w");
    
    for (t = 0.0; t < 2e5; t = t+1000) {
        remain = exp(-lamada * t);
        printf("the proportion of remaining atoms is %f\n",remain);
        
        /* write the output to the file */
        fprintf(fp,"the proportion of remaining atoms is %f\n", remain);
    }
    /* close the output file */
    fclose(fp);
    
    return 0;
}
