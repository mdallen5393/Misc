#include "main.h"

int main(int argc, char *argv[])
{
    int *my_arr = malloc(sizeof(int) * argc);
    int *sorted;
    int verbose_flag = 0, desc_flag = 0, repeats_flag = 0;
    int size = 0;

    for (int i = 1; i < argc; i++)
    {
        /* Check for verbose flag */
        if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0)
            verbose_flag = 1;
        else if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--desc") == 0)
            desc_flag = 1;
        else if (strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "--repeats") == 0)
            repeats_flag = 1;
        else
        {
            /* Populate array to be sorted */
            my_arr[size] = atoi(argv[i]);
            size++;
        }
    }

    SortedArray result = stalin_sort(size, my_arr, verbose_flag, repeats_flag, desc_flag);
    print_array(result.size, result.arr);

    return (0);
}

void print_array(int size, int *arr)
{
    int i;

    printf("%i elements in array\n", size);

    printf("Array: [");
    for (i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");
}

void verbose_print_array(int size, int *arr, int before)
{
    int i;

    if (before)
        printf("...BEFORE SORTING: ");
    if (!before)
        printf("...AFTER SORTING: ");
    printf("%i elements in array\n", size);

    printf("...Array: [");
    for (i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");
}