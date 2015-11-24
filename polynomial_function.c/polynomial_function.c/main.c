//
//  main.c
//  polynomial_function.c
//
//  Created by wei on 15/2/7.
//  Copyright (c) 2015年 wei. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* program to evaluate the polynomial x^3 + 2x^2 - 120x +11/3 */
/* for a value of x given by the user on the command line     */
float roots(float x)
{
    float poly;
    poly = pow(x, 3.0) +2.0*pow(x, 2.0) - 120.0*x +11.0/3.0;
    return poly;
}

int main(int argc, const char * argv[]) {
    /* declare variables */
    float x;
    float roots(float x);
    float results;
    x = atof(argv[1]);
    
    results = roots(x);
    
    /* print to screen */
    printf("For x = %f the value of the polynomial is %f\n", x, results);
    
    return 0;
}
