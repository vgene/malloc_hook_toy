#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

#define NUM_ITERATIONS 100000000

static size_t malloc_count = 0;
static size_t free_count = 0;

static void *(*real_malloc)(size_t, const void *);
static void (*real_free)(void *, const void *);

void *malloc_hook(size_t size, const void *caller)
{
    // malloc_count++;
    __malloc_hook = real_malloc;
    void *result = malloc(size);
    __malloc_hook = malloc_hook;
    return result;
}

void free_hook(void* ptr, const void* caller) {
    // free_count++;
    __free_hook = real_free;
    free(ptr);
    __free_hook = free_hook;
}

int main() {
    srand(time(NULL)); // seed the random number generator

    real_malloc = __malloc_hook;
    real_free = __free_hook;

    __malloc_hook = malloc_hook;
    __free_hook = free_hook;
    
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        void* ptr = malloc(10); // allocate memory
        *(volatile int*)ptr = 42;
        free(ptr); // free memory immediately
    }

    printf("malloc called %zu times\n", malloc_count);
    printf("free called %zu times\n", free_count);
    
    return 0;
}
