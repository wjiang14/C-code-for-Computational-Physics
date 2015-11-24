//
//  main.c
//  energy_of_gas
//
//  Created by wei on 15/1/26.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"
#include <string.h>

int main(int argc, const char * argv[]) {
    float r, delta_t, e;
    int n;
    char* str_1 = "monatomic";
    char* str_2 = "diatomic";
    
    /* r is gas constant */
    r = 8.31;
    n = atoi(argv[1]);
    delta_t = atof(argv[2]);
    if (strcmp(argv[3], str_1) == 0) {
        e = 1.5 *n*r*delta_t;
        printf("gas is monatomic, energy is %f",e);
    }
    else if(strcmp(argv[3], str_2) == 0) {
        e = 2.5 *n*r*delta_t;
        printf("gas is monatomic, energy is %f",e);
    }
    return 0;
}
