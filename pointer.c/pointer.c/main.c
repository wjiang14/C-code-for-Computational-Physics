//
//  main.c
//  pointer.c
//
//  Created by wei on 15/2/1.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    float x;
    float y;
    float *p;
    
    x = 10.0;
    p = &x;
    
    y = *p;
    printf("%f",y);
    printf("p");
    return 0;
}
