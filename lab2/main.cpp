#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <time.h>
#include <assert.h>

typedef uint8_t my_int_t[64];
const size_t sz = 128 * 1024 * 1024;

void mesureArrayMult(my_int_t* arr, size_t step) {
    clock_t start_time = clock();

    for (size_t i = 0; i < sz; i ++) {
        arr[i][0] *= i;
    }

    double work_time_us = (clock() - start_time) * (1000. / CLOCKS_PER_SEC);
    printf("%4zd (%4zd): %7.3lfus\n", step, sizeof(my_int_t) * step, work_time_us);
}

int main()
{


    my_int_t* arr = (my_int_t*)malloc(64 * sz);
    //assert(arr);

    memset(arr, '\0', sizeof(arr[0]) * sz);

    size_t i = 2;
    for (; i < 20; i += 1) { mesureArrayMult(arr, i); }
    //for (; i <= 1024; i *= 2) { mesureArrayMult(arr, sz, i); }

    free(arr);

    return 0;
}