#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_eigen.h>

/* Dimension of Matrix and Vectors */
#define DIM 3

int main(void)
{
    double a_data[] = { 1.0, 2.0, 3.0,
        2.0, 2.0, 3.0,
        3.0, 3.0, 3.0 };
    int i, j;
    gsl_vector_complex *eval;
    gsl_matrix_complex *evec;
    gsl_eigen_nonsymmv_workspace *w;
    
    gsl_matrix_view m
    = gsl_matrix_view_array(a_data, 3, 3);
    
    
    printf("The matrix is\n");
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 3; ++j)
            printf(j==2?"%6.3f\n":"%6.3f ", gsl_matrix_get(&m.matrix,i,j));
    

    
    /* Get Eigensystem of Companion Matrix : Eigenvalues and Eigenvectors */
    
    /* Initialize workspace and eigenvectors stored, and set matrix */
    evec = gsl_matrix_complex_alloc(DIM, DIM);
    eval = gsl_vector_complex_alloc(DIM);
    w = gsl_eigen_nonsymmv_alloc(DIM);
    
    /* get eigenvalues and its eigenvectors (matrix is destroyed) */
    gsl_eigen_nonsymmv(&m.matrix, eval, evec, w);
    
    /* Sort eigenvalues and eigenvectors */
    gsl_eigen_nonsymmv_sort(eval, evec, GSL_EIGEN_SORT_ABS_DESC);
    
    
    {
        
        for (i = 0; i < 3; i++)
        {
            gsl_complex eval_i
            = gsl_vector_complex_get (eval, i);
            gsl_vector_complex_view evec_i
            = gsl_matrix_complex_column (evec, i);
            
            printf ("\neigenvalue = %g + %gi\n", GSL_REAL(eval_i), GSL_IMAG(eval_i));
            printf ("eigenvector = \n");
            
            for (j = 0; j < 3; ++j)
            {
                gsl_complex z =
                gsl_vector_complex_get(&evec_i.vector, j);
                printf("%g + %gi\n", GSL_REAL(z), GSL_IMAG(z));
            }
        }
    }
    
    gsl_vector_complex_free (eval);
    gsl_matrix_complex_free (evec);
    gsl_eigen_nonsymmv_free (w);
    
    
    return 0;
}