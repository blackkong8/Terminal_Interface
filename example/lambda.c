#include <stdio.h>
#include <stdlib.h>
#include "../lambda.h"

typedef enum
{
    True,
    False
} bool;

int *filter(int *arr, int size, bool(lambda_ptr f)(int))
{
    int *n_arr = malloc(sizeof(int) * (size + 1));
    int idx = 0;
    for (int i = 0; i < size; i++)
        if (f(arr[i]))
            n_arr[idx++] = arr[i];
    n_arr[idx] = '\0';
    return n_arr;
}

int main(void)
{
    int arr[] = {0, 1, 2, 3};
    filter(arr, 4, lambda(
                       bool, (int i) { return i ? False : True; }));
    return 0;
}