//
//  main.c
//  caculate_fre
//
//  Created by wei on 15/1/25.
//  Copyright (c) 2015年 wei. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    float wavelength;
    float frequency;
    float c;
    
    /* define speed of light*/
    c = 3.0e8;
    wavelength = atof(argv[1]);
    frequency = c / wavelength;

    printf("The frequency of light corresponding to wavelength %f is %e\n", wavelength, frequency);
    return 0;
}
