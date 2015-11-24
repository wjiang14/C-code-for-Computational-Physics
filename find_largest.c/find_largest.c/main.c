//
//  main.c
//  find_largest.c
//
//  Created by wei on 15/6/8.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>

#define N_row 10
#define N_line 10

int find_largest(int *p, int a[N_row][N_line]){
    int max = a[0][0];
    for (p = &a[0][0]; p <= &a[N_row][N_line]; p++) {
        if (*p > max) {
            max = *p;
        }
    };
    printf("%d", max);
    return 0;
}

int main(int argc, const char * argv[]) {
    int *p;
    int a[N_row][N_line] = {{1,3,4,5,6,3,2,5,6,8},{4,3,1,7,8,3,2,9,6,0}};
    find_largest(p, a);
    return 0;
}
