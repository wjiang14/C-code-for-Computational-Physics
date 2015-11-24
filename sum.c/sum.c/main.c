//
//  main.c
//  sum.c
//
//  Created by wei on 15/6/8.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>

#define N 10

int main(int argc, const char * argv[]) {
    int sum, *p;
    
    int a[N] = {1,2,3,4,5,6,7,8,9,10};
    
    sum = 0;
    for (p = a; p < a + N; p++) {
        sum = sum + *p;
    }
    printf("%d", sum);
    return 0;
}
