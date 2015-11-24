//
//  main.c
//  test_function.c
//
//  Created by wei on 15/2/8.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>
#include <math.h>


float quad_solve(float *root_p, float *root_n, float a, float b, float c){
    float d = b*b -4.0*a*c;
    *root_p = (-b + sqrt(d))/(2.0*a);
    *root_n = (-b + sqrt(d))/(2.0*a);
    printf("%f %f", *root_n, root_p);
    return d;
}

int main(int argc, const char * argv[]) {
    float root_p, root_n;
    quad_solve(&root_p, &root_n, 7.0, 15.0, -2.0);
}