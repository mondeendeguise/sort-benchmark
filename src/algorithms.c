#include "algorithms.h"
#include "helper.h"

#include <stdbool.h>
#include <sys/types.h>
#include <assert.h>

void selection_sort(int *arr, size_t size)
{
    for(size_t i = 0; i < size; ++i) {
        size_t l = i;
        for(size_t j = i; j < size; ++j) {
            if(arr[j] < arr[l]) l = j;
        }
        swap(arr+i, arr+l);
    }
}

void insertion_sort_a(int *arr, size_t size)
{
    for(size_t i = 1; i < size; ++i) {
        for(size_t j = i; j > 0 && arr[j-1] > arr[j]; --j) {
            swap(&arr[j], &arr[j-1]);
        }
    }
}

void insertion_sort_b(int *arr, size_t size)
{
    for(size_t i = 1; i < size; ++i) {
        int x = arr[i];
        size_t j;
        for(j = i; j > 0 && arr[j-1] > x; --j) {
            arr[j] = arr[j-1];
        }
        arr[j] = x;
    }
}

void insertion_sort_recursive(int *arr, size_t size)
{
    if(size > 0) {
        insertion_sort_recursive(arr, size-1);
        int x = arr[size];
        ssize_t j = size-1;
        while(j >= 0 && arr[j] > x) {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = x;
    }
}

void bubble_sort(int *arr, size_t size)
{
    for(size_t i = 0; i < size-1; ++i) {
        bool swapped = false;
        for(size_t j = 0; j < size - i - 1; ++j) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

void merge_sort(int *arr, size_t size)
{
    (void) arr;
    (void) size;
    assert(0 && "Merge Sort not yet implemented");
}
