#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/malloc_hook.h"


bool hook_active = false;

static size_t malloc_count = 0;
static size_t free_count = 0;

extern void *__libc_malloc(size_t size);
extern void __libc_free(void *ptr);

void *malloc(size_t size)
{
    if (hook_active)
    {
        malloc_count++;
    }

    return __libc_malloc(size);
}

void free(void *ptr)
{
    if (hook_active)
    {
        free_count++;
    }

    __libc_free(ptr);
}

size_t get_malloc_count()
{
    return malloc_count;
}

size_t get_free_count()
{
    return free_count;
}