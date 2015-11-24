//
//  main.c
//  number_of_atom_set4
//
//  Created by wei on 15/1/27.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"
#include "math.h"

int main(int argc, const char * argv[]) {
    
    float t = 0, tau, remain, lamada;
    /* input parameter */
    tau = 5.0e4;
    lamada = log(2)/tau;
    
    /* initialize the state of atoms */
    remain = exp(-lamada * t);
    
    /* cacluate the number proportion of atoms */
    do {
        remain = exp(-lamada * t);
        t = t + 1000;
        printf("the proportion of remaining atoms is %f\n", remain);
    } while (remain >= 0.1);
    return 0;
}
