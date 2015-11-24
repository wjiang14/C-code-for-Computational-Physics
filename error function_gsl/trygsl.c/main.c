//
//  main.c
//  trygsl.c
//
//  Created by wei on 15/4/4.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>
#include <gsl/gsl_sf_erf.h>
#include <time.h>


double call(double x){
    return gsl_sf_erf (x);
}

int
main (void)
{
    clock_t start, finish;
    double  duration;
    /* duration of program */
    start = clock();
    
    double interval = 0.0;
    FILE *fp;
    fp = fopen( "output.txt", "w" );
    while (-5 + interval < 5) {
        printf("%e\n", call(-5 + interval));
        fprintf(fp, "%e %e\n", -5 + interval, call(-5 + interval));
        interval = interval + 1e-5;
    }
    fclose( fp );
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    
}