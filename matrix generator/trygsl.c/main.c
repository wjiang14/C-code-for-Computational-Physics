#include <stdio.h>
#include <gsl/gsl_math.h>
#include <time.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_permutation.h>
#include <gsl/gsl_linalg.h>

/* Dimension of Matrix and Vectors */

int main(void)
{
    
    /*int i, j;*/
    const gsl_rng_type * T;
    gsl_rng * r;
    
    gsl_rng_env_setup();
    T = gsl_rng_default;
    r = gsl_rng_alloc (T);
    int s;
    double det;
    
    
    
    
    
    double n = 500.0;
    
    FILE *fp;
    fp = fopen( "output.txt", "w" );
    for (int i = 0; i < 4; i ++) {
        clock_t start, finish;
        double  duration;
        /* duration of program */
        start = clock();
        
        gsl_matrix *m = gsl_matrix_alloc(n, n);
        
        for (int inter = 0; inter < n; inter++) {
            for (int inter2 = 0; inter2 < n; inter2++) {
                double u = gsl_rng_uniform (r);
                gsl_matrix_set(m, inter, inter2, u);
            }
        }
        
        /* take elements of matrix */
        
        /*for (int i = 0; i < 3; i++){
         for (int j = 0; j < 3; j++){
         printf ("m(%d,%d) = %g\n", i, j,
         gsl_matrix_get (m1, i, j));
         }
        }*/
        
        gsl_permutation*p = gsl_permutation_calloc(n);
        gsl_linalg_LU_decomp (m, p, &s);
        det = gsl_linalg_LU_det(m, s);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
        printf( "%e %f seconds\n",log(n), log(duration) );
        fprintf(fp, "%e %e\n",log(n), log(duration));
        n = n + 500;
        gsl_permutation_free(p);
        gsl_matrix_free (m);

    }
    fclose( fp );
   
    
    gsl_rng_free (r);
   
    return 0;
    
}