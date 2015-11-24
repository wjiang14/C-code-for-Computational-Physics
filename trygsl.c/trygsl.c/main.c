//
//  main.c
//  trygsl.c
//
//  Created by wei on 15/4/4.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>
#include "math.h"
#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_roots.h>

#include "demo_fn.h"
#include "demo_fn.c"

double myfun(double x){
    double function = 3*sin(x)/x;
    return function;
}

double differential1(double (*func)(double x), double x, double h){
    double result = (- func(x + 2*h) + 8*func(x + h) - 8*func(x - h) + func(x - 2*h))/(12*h);
    return result;
    
}


int
main (void)
{
    double h = 0.001, interval = 0.2;
    double x = -2.0;
    int n = 0;
    double newfunc[10][2];
    double result[10][2];
    
    for (int i = 0; i < 100; i++) {
        newfunc[i][1] = differential1(myfun, x, h);
        newfunc[i][0] = x;
        x = x + interval;
        if (newfunc[i][1] * newfunc[i-1][1] < 0) {
            result[n][0] = newfunc[i-1][0];
            result[n][1] = newfunc[i][0];
            printf("Maximum of function located between %e, %e\n",result[n][0],result[n][1]);
            n++;
        }
        
    }
    
    int status, j = 0;
    int iter = 0, max_iter = 100;
    double theta, k = 2*3.1415926/(589.29e-9), a = 2.8e-6;
    do{
        const gsl_root_fsolver_type *T;
        gsl_root_fsolver *s;
        double r = 0;
        double x_lo = result[j][0], x_hi = result[j][1];
        gsl_function F;
        struct differential_params params = {0.01};
        F.function = &differential_deriv;
        F.params = &params;
        T = gsl_root_fsolver_brent;
        s = gsl_root_fsolver_alloc (T);
        gsl_root_fsolver_set (s, &F, x_lo, x_hi);
                                                  
        printf ("using %s method\n",
        gsl_root_fsolver_name (s));
        printf ("%5s [%9s, %9s] %9s %9s\n",
                "iter", "lower", "upper", "root", "err(est), theta");
        do
        {
            iter++;
            status = gsl_root_fsolver_iterate (s);
            r = gsl_root_fsolver_root (s);
            x_lo = gsl_root_fsolver_x_lower (s);
            x_hi = gsl_root_fsolver_x_upper (s);
            status = gsl_root_test_interval (x_lo, x_hi,
                                             0, 0.001);
            
            if (status == GSL_SUCCESS)
                printf ("Converged:\n");
            theta = 180*asin(2*r/(k*a))/3.1415926;
            printf ("%5d [%.7f, %.7f] %.7f %.7f %.7f\n",
                    iter, x_lo, x_hi,
                    r, x_hi - x_lo, theta);
        }
        while (status == GSL_CONTINUE && iter < max_iter);
        
        gsl_root_fsolver_free (s);
        j++;
    }
    while (j <= 4) ;
    
    return status;
}
