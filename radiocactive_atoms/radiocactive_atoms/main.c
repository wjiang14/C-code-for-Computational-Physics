//
//  main.c
//  radiocactive_atoms
//
//  Created by wei on 15/1/26.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    /* define viables */
    float t, lamada, tau, remain;
    
    /* input parameter */
    t = atof(argv[1]);
    tau = atof(argv[2]);
    
    lamada = log(2)/tau;
    remain = exp(-lamada * t);
    
    printf("the proportion of remaining radioactive atoms equal %f\n", remain);
    return 0;

}
