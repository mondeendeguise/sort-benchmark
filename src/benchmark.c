#include "benchmark.h"
#include "helper.h"

#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>
#include <stdio.h>

#define time_function(function, ...)                              \
    clock_begin = clock();                                        \
    (function)((__VA_ARGS__));                                    \
    clock_end = clock();                                          \
    time = ((double) (clock_end - clock_begin) / CLOCKS_PER_SEC);

void perform_benchmark(void (*f)(int *, size_t), size_t iterations, size_t array_size)
{
    double results[iterations];

    int *arr = malloc(sizeof(int) * array_size);

    for(size_t i = 0; i < iterations; ++i) {
        fill_range(arr, 0, array_size);
        shuffle(arr, array_size);

        clock_t clock_begin, clock_end;
        double time;
        
        clock_begin = clock();
        f(arr, array_size);
        clock_end = clock();
        time = ((double) (clock_end - clock_begin) / CLOCKS_PER_SEC);

        results[i] = time;
    }

    free(arr);

    double average_time = 0;
    double total_time = 0;
    for(size_t i = 0; i < iterations; ++i) {
        total_time += results[i];
    }

    average_time = total_time / iterations;

    printf("completed %zu iterations of size %zu in %f seconds "
           "with an average time of %f seconds.\n",
           iterations, array_size, total_time, average_time);
}
