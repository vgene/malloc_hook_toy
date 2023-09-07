#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "include/malloc_hook.h"

#define NUM_ITERATIONS 100000000

extern bool hook_active;

int main() {
    srand(time(NULL)); // seed the random number generator

    hook_active = true;
    
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        void* ptr = malloc(10); // allocate memory
        *(volatile int*)ptr = 42;
        free(ptr); // free memory immediately
    }
    
    printf("malloc called %zu times\n", get_malloc_count());
    printf("free called %zu times\n", get_free_count());
    
    return 0;
}
