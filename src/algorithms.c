#include "algorithms.h"
#include "helper.h"

void bubble_sort(int *arr, size_t size)
{
    for(size_t i = 0; i < size; ++i) {
        size_t l = i;
        for(size_t j = i; j < size; ++j) {
            if(arr[j] < arr[l]) l = j;
        }
        swap(arr+i, arr+l);
    }
}
