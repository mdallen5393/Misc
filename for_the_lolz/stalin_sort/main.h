#ifndef MAIN_H
#define MAIN_H

typedef struct SortedArray {
    int *arr;
    int size;
} SortedArray;

/* Standard Libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Function prototype */
SortedArray stalin_sort(int size, int *arr, int verbose, int keep_repeats, int desc);
void print_array(int size, int *arr);
void verbose_print_array(int size, int *arr, int before);

#endif
