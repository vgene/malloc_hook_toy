#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITERATIONS 100000000
static size_t malloc_count = 0;
static size_t free_count = 0;

int main() {
    srand(time(NULL)); // seed the random number generator
    
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        void* ptr = malloc(10); // allocate memory
        *(volatile int*)ptr = 42;
        free(ptr); // free memory immediately
    }
    
    printf("malloc called %zu times\n", malloc_count);
    printf("free called %zu times\n", free_count);
    
    return 0;
}
