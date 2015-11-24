//
//  main.c
//  is_prime.c
//
//  Created by wei on 15/6/2.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>

#define TRUE 11
#define FALSE 0

typedef int Bool;

Bool is_prime(int n){
    int divisor;
    
    if (n <= 1) {
        return FALSE;
    }
    for (divisor = 2; divisor * divisor <= n; divisor++) {
        if (n % divisor == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

int main(int argc, const char * argv[]) {
    int n;
    
    printf("enter a number here");
    scanf("%d", &n);
    if (is_prime(n)) {
        printf("Prime\n");
    }
    else
        printf("Not prime\n");
}
