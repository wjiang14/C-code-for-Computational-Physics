//
//  main.c
//  evaluate polynomial for computational physics
//
//  Created by wei on 15/1/24.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* program to evaluate the polynomial x^3 + 2x^2 - 120x +11/3 */
/* for a value of x given by the user on the command line     */

int main(int argc, const char * argv[]) {
    /* declare variables */
    float x; /* the indepdendent variable x */
    float poly; /* the value of the polynomial at x */
    
    /* parse the command line argument */
    x = atof(argv[1]);
    
    /* subsitute in polynomial */
    poly = pow(x, 3.0) +2.0*pow(x, 2.0) - 120.0*x +11.0/3.0;
    
    /* print to screen */
    printf("For x = %f the value of the polynomial is %f\n", x, poly);
    
    return 0;
}
