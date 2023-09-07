## Malloc Hook Method Exploration

Since `__malloc_hook` has been deprecated and removed, an alternative is
necessary for doing malloc hook. The functionality requirement is a hook
function that covers all malloc-related functions and also the performance
should be on par.

This repo implements a malloc hook method by replacing malloc (a weak symbol)
and calls `__libc_` functions internally.

A quick measurement is done by doing a fixed number of iterations of malloc
and free of a fixed size. The measurement sees an improvement compared to the
old `__malloc_hook` method and small overhead compared to raw malloc.

## Performance Measurement

```
Running performance test: install/bin/hook_performance_test
real    0m1.816s
user    0m1.816s
sys     0m0.000s

Running performance test: install/bin/new_hook_performance_test
real    0m1.220s
user    0m1.219s
sys     0m0.000s

Running performance test: install/bin/raw_performance_test
real    0m1.156s
user    0m1.156s
sys     0m0.000s
```