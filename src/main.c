#include <stdlib.h>
#include <time.h>

#include "algorithms.h"
#include "benchmark.h"

int main(void)
{
    srand(time(0));
    perform_benchmark(bubble_sort, 1000, 1000);
    return 0;
}
