//
//  main.c
//  quadratic_set3.c
//
//  Created by wei on 15/1/26.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>
#include "math.h"
#include "stdlib.h"

int main(int argc, const char * argv[]) {
    
    float a, b, c;
    float discriminant, pvalue, nvalue;

    
    /* solve equation of ax^2 + bx + c */
    discriminant = pow(b, 2) - 4*a*c;
    pvalue = (-b + sqrt(discriminant))/(2*a);
    nvalue = (-b - sqrt(discriminant))/(2*a);
    
    if (argc == 4) {
        
        a = atof(argv[1]);
        b = atof(argv[2]);
        c = atof(argv[3]);
        
        if (discriminant < 0) {
            fprintf(stderr, "The roots are complex\n");
            return 1;
        }
        
        else if (discriminant >= 0){
            printf("The solutions of equation %fx^2 + %fx + %f are %f and %f", a, b, c, pvalue, nvalue);
            
        }
        
    }
    
    else{
        fprintf(stderr, "please input 3 parameters.\n");
    }
    
        return 0;
}
