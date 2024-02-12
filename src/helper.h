#pragma once

#include <stddef.h>

void swap(int *x, int *y);

int rand_int(int min, int max);

void random_array(int *arr, size_t size, int min, int max);
void fill_range(int *arr, size_t min, size_t max);
void shuffle(int *arr, size_t size);

void print_array(int *arr, size_t size);
