//
//  main.c
//  reverse.c
//
//  Created by wei on 15/6/8.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>

#define N 10

int main(int argc, const char * argv[]) {
    int a[N], *p;
    
    printf("input %d numbers", N);
    for (p = a; p < a + N; p++) {
        scanf("%d", p);
    }
    printf("in reversed order");
    for (p = a + N - 1; p >= a; p--) {
        printf("%d",*p);
    }
    return 0;
}
