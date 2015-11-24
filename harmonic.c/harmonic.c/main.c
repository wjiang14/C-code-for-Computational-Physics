//
//  main.c
//  harmonic.c
//
//  Created by wei on 15/2/2.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main( int argc, char *argv[] )
{
    /* declare viables*/
    int i = 0;
    float omega, b, x[i], t;
    /* a pointer to output file*/
    FILE *fp;
    
    omega = atof(argv[1]);
    b = atof(argv[2]);
    fp = fopen("results.txt", "w");
    
    for(t = 0.0; t < 5.5; t = t + 0.5){
            x[i] = b*cos(omega*t);
            x[i+1] = -omega*b*sin(omega*t);
            x[i+2] = -pow(omega, 2)*b*cos(omega*t);
            fprintf(fp, "%f %f %f %f\n", t, x[i], x[i+1], x[i+2]);
    }
    
    /* close the output file */
    fclose(fp);
    return 0;
}