#include "main.h"

int main(int argc, char *argv[])
{
    int *my_arr = malloc(sizeof(int) * argc);
    int v_flag = 0;
    int size = 0;

    for (int i = 1; i < argc; i++)
    {
        /* Check for verbose flag */
        if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0)
            v_flag = 1;
        else
        {
            /* Populate array to be sorted */
            my_arr[size] = atoi(argv[i]);
            size++;
        }
    }

    stalin_sort(size, my_arr, v_flag);

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