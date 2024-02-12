#pragma once

#include <stddef.h>

void perform_benchmark(void (*f)(int *, size_t), size_t iterations, size_t array_size);
