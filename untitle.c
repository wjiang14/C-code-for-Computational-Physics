#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>

int
func (double t, const double y[], double f[],
      void *params)
{
    double mu = *(double *)params;
    f[0] = mu*y[0];
    return GSL_SUCCESS;
}

int
jac (double t, const double y[], double *dfdy,
     double dfdt[], void *params)
{
    double mu = *(double *)params;
    gsl_matrix_view dfdy_mat
    = gsl_matrix_view_array (dfdy, 2, 2);
    gsl_matrix * m = &dfdy_mat.matrix;
    gsl_matrix_set (m, 0, 0, 0.0);
    gsl_matrix_set (m, 0, 1, 1.0);
    gsl_matrix_set (m, 1, 0, mu);
    gsl_matrix_set (m, 1, 1, 0.0);
    dfdt[0] = 0.0;
    dfdt[1] = 0.0;
    return GSL_SUCCESS;
}

int
main (void)
{
    FILE *fp;
    double mu = 1;
    gsl_odeiv2_system sys = {func, NULL, 1, &mu};
    
    gsl_odeiv2_driver * d =
    gsl_odeiv2_driver_alloc_y_new (&sys, gsl_odeiv2_step_rk8pd,
                                   1e-6, 1e-6, 0.0);
    int i;
    double x = 0.0, x1 = 2.0;
    double y[1] = { 1.0 };
    fp = fopen( "output.txt", "w" );
    
    for (i = 1; i <= 100; i++)
    {
        double ti = i * x1 / 100.0;
        int status = gsl_odeiv2_driver_apply (d, &x, ti, y);
        
        if (status != GSL_SUCCESS)
        {
            printf ("error, return value=%d\n", status);
            break;
        }
        
        printf ("%.5e %.5e\n", x, y[0]);
        fprintf( fp, "%.5e %.5e\n", x, y[0]);
    }
    fclose( fp );
    
    gsl_odeiv2_driver_free (d);
    return 0;
}