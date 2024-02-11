#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>
#include <stdio.h>

#define time_function(f, x, y)                              \
    clock_begin = clock();                                  \
    (f)((x), (y));                                          \
    clock_end = clock();                                    \
    time = ((double) (clock_end - clock_begin) / CLOCKS_PER_SEC);

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

void range(int *arr, size_t min, size_t max)
{
    for(size_t i = 0; i < max-min; ++i) {
        arr[i] = min + i;
    }
}

void shuffle(int *arr, size_t size)
{
    for(int i = size-1; i > 0; --i) {
        int j = rand_int(0, i);
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

void time_bubble_sort(size_t times, size_t array_length)
{
    double results[times];
    for(size_t i = 0; i < times; ++i) {
        int *arr = malloc(sizeof(int) * array_length);
        range(arr, 0, array_length);
        shuffle(arr, array_length);

        clock_t clock_begin, clock_end;
        double time;
        time_function(bubble_sort, arr, array_length);
        results[i] = time;
        free(arr);
    }
    double average_time = 0;
    double total_time = 0;
    for(size_t i = 0; i < times; ++i) {
        total_time += results[i];
    }
    average_time = total_time / times;
    printf("Bubble Sort completed %zu iterations with array size %zu in %f "
           "seconds with an average of %f seconds.\n",
           times, array_length, total_time, average_time);
}

int main(void)
{
    srand(time(0));
    time_bubble_sort(1000, 1000);
    return 0;
}
