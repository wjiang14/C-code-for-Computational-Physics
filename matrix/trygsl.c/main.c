//
//  main.c
//  trygsl.c
//
//  Created by wei on 15/4/4.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_permutation.h>
#include <gsl/gsl_linalg.h>


int main(void)
{
    double a_data[] = { 1.0, 2.0, 3.0,
        2.0, 2.0, 3.0,
        3.0, 3.0, 3.0 };
    int i, j;
   
    
    gsl_matrix_view m
    = gsl_matrix_view_array(a_data, 3, 3);
    
    
    printf("The matrix is\n");
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 3; ++j)
            printf(j==2?"%6.3f\n":"%6.3f ", gsl_matrix_get(&m.matrix,i,j));
    
    gsl_matrix* inverse = gsl_matrix_alloc(3, 3);
    gsl_permutation *p = gsl_permutation_alloc(3);
    int s = 0;
    gsl_linalg_LU_decomp(&m.matrix, p, &s);
    gsl_linalg_LU_invert(&m.matrix, p, inverse);
    
    printf("The inverse matrix is\n");
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 3; ++j)
            printf(j==2?"%6.3f\n":"%6.3f ", gsl_matrix_get(inverse,i,j));
    printf("The det of matrix is %f\n", gsl_linalg_LU_det (&m.matrix, s));
    gsl_permutation_free(p);
    gsl_matrix_free(inverse);
   
    return 0;
}