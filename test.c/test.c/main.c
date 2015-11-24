//
//  main.c
//  test.c
//
//  Created by wei on 15/3/22.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double trap( double a, double b){
    
    double final, f, result = 0;
    
    f = abs((0.1/2)*(exp(a) + 2*result + exp(b)));
    while (f - 0.746824 >= 0.0001) {
        result = result + exp(a + 0.1*i);
        i++;
        final = (0.1/2)*(func(a) + 2*result + func(b));
        printf("%d", i);
    }
}
