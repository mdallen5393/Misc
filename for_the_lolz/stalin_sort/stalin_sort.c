#include "main.h"

SortedArray stalin_sort(int size, int *arr, int verbose, int keep_repeats, int desc)
{
    int i, sorted_index = 0;
    int *sorted = malloc(sizeof(int) * size);
    SortedArray result;

    if (verbose)
    {
        printf("Running in verbose mode...\n");
        verbose_print_array(size, arr, 1);
    }

    sorted[sorted_index] = arr[0];
    sorted_index++;

    for (i = 1; i < size; i++)
    {
        if (desc)
        {
            if ((keep_repeats && arr[i] <= sorted[sorted_index - 1]) || (!keep_repeats && arr[i] < sorted[sorted_index - 1]))
            {
                sorted[sorted_index] = arr[i];
                sorted_index++;
            }
            else
            {
                if (verbose)
                    printf("......VALUE %d ELIMINATED\n", arr[i]);
            }
        }
        else
        {
            if ((keep_repeats && arr[i] >= sorted[sorted_index - 1]) || (!keep_repeats && arr[i] > sorted[sorted_index - 1]))
            {
                sorted[sorted_index] = arr[i];
                sorted_index++;
            }
            else
            {
                if (verbose)
                    printf("......VALUE %d ELIMINATED\n", arr[i]);
            }
        }
    }

    if (verbose)
    {
        verbose_print_array(sorted_index, sorted, 0);
        printf("Sorting complete\n");
    }

    result.arr = sorted;
    result.size = sorted_index;

    return result;
}
