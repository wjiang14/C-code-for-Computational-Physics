//
//  main.c
//  set1_new_polynomial.c
//
//  Created by wei on 15/1/27.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* program to evaluate the polynomial 3x^2/5 + 4x - 2 */
/* for a value of x given by the user on the command line     */

int main(int argc, const char * argv[]) {
    /* declare variables */
    float x; /* the indepdendent variable x */
    float poly; /* the value of the polynomial at x */
    
    /* parse the command line argument */
    x = atof(argv[1]);
    
    /* subsitute in polynomial */
    poly = 3.0*pow(x, 2.0)/5 + 4.0*x- 2;
    
    /* print to screen */
    printf("For x = %f the value of the polynomial is %f\n", x, poly);
    
    return 0;
}
