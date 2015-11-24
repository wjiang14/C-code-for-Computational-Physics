//
//  main.c
//  quick_sort.c
//
//  Created by wei on 15/6/5.
//  Copyright (c) 2015年 wei. All rights reserved.
//




#include <stdio.h>

#define N 10

void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);

int main(int argc, const char * argv[]) {
    int a[N], i;
    
    printf("please %d numbers to be sorted", N);
    for (i = 0; i < N; ++i)
    {
        scanf("%d", &a[i]);
    }
    
    quicksort(a, 0, N - 1);
    printf("in sorted order:");
    for (i = 0; i < N; ++i)
    {
        printf("%d", a[i]);
    }
    printf("\n");
    
    return 0;
}


/* define split function to sort two part for a given 1D array */
int spilt(int a[], int low, int high){
    int part_element = a[low];
    
    for(;;){
        while(low < high && part_element <= a[high]){
            high--;
        }
        if(low >= high){
            break;
        }
        a[low++] = a[high];
        
        while(low < high && part_element >= low){
            low--;
        }
        if(low >= high){
            break;
        }
        a[high--] = a[low];
    }
    
    a[high] = part_element;
    return high;
}

/* recursion function */
void quicksort(int a[], int low, int high){
    int middle;
    
    if(low >= high){
        return;
    }
    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

