//
//  main.c
//  simple_harmonic_oscillator.c
//
//  Created by wei on 15/2/8.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/* declare the function */

int shm(double *x, double *v, double *a, int n, double B, double omega, double t_start, double t_end){
    /* declare viables*/
    int i = 0;
    double t, result[i];
    /* a pointer to output file*/
    FILE *fp;

    fp = fopen("results.txt", "w");
    
    for(t = t_start; t < t_end; t = t + (t_end - t_start)/n){
        result[i] = B*cos(omega*t);
        result[i+1] = -omega*B*sin(omega*t);
        result[i+2] = -pow(omega, 2)*B*cos(omega*t);
        x = &result[i];
        v = &result[i+1];
        a = &result[i+2];
        fprintf(fp, "%f %f %f %f\n", t, *x, *v, *a);
        printf("%f %f %f %f\n", t, *x, *v, *a);
    }
    
    /* close the output file */
    fclose(fp);
    return n;
}

int main( int argc, char *argv[] )
{
    double q, w, r;
    shm(&q, &w, &r, 40, 0.4, 2.0, 1.0, 20.0);
}