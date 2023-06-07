#include "main.h"

int *stalin_sort(int size, int *arr, int verbose)
{
    int i;

    if (verbose)
    {
        printf("Running in verbose mode...\n");
        // size--;
    }

    print_array(size, arr);
    return arr;
}
