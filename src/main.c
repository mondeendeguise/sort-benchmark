#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "algorithms.h"
#include "benchmark.h"

int main(void)
{
    srand(time(0));

    printf("Selection sort ");
    perform_benchmark(selection_sort, 1000, 1000);

    printf("Insertion sort A ");
    perform_benchmark(insertion_sort_a, 1000, 1000);

    printf("Insertion Sort B ");
    perform_benchmark(insertion_sort_b, 1000, 1000);

    printf("Insertion Sort Recursive ");
    perform_benchmark(insertion_sort_recursive, 1000, 1000);

    printf("Bubble Sort ");
    perform_benchmark(bubble_sort, 1000, 1000);

    return 0;
}
