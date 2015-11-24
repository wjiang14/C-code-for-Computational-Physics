struct differential_params
{
    double a;
};

double differential (double x, void *params);
double differential_deriv (double x, void *params);
void differential_fdf (double x, void *params,
                    double *y, double *dy);