#include "helper.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

int rand_int(int min, int max)
{
    return (int) (((max - min) * (rand() / (float) RAND_MAX)) + min);
}

void random_array(int *arr, size_t size, int min, int max)
{
    for(size_t i = 0; i < size; ++i) {
        arr[i] = rand_int(min, max);
    }
}

void fill_range(int *arr, size_t min, size_t max)
{
    for(size_t i = 0; i < (max - min); ++i) {
        arr[i] = min + i;
    }
}

void shuffle(int *arr, size_t size)
{
    for(size_t i = size - 1; i > 0; --i) {
        size_t j = rand_int(0, i);
        swap(&arr[i], &arr[j]);
    }
}

void print_array(int *arr, size_t size)
{
    for(size_t i = 0; i < size; ++i) {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

