double
differential (double x, void *params)
{
    struct differential_params *p
    = (struct differential_params *) params;
    
    double a = p->a;
    
    return a*sin(x)/x;
}

double
differential_deriv (double x, void *params)
{
    struct differential_params *p
    = (struct differential_params *) params;
    
    double a = p->a;
    
    return (-3*sin(x+2*a)/(x+2*a) + 8*3*sin(x+a)/(x+a) - 8*3*sin(x-a)/(x-a) + 3*sin(x-2*a)/(x-2*a))/(12*a);
}

void
differential_fdf (double x, void *params,
               double *y, double *dy)
{
    struct differential_params *p
    = (struct differential_params *) params;
    
    double a = p->a;
    
    *y = a*sin(x)/x;
    *dy = a*cos(x)/x - a*sin(x)/pow(x,2);
}
