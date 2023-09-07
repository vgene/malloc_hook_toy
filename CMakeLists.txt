cmake_minimum_required(VERSION 3.10)

project(malloc_toy)

# Add source files
set(SOURCES src/malloc_hook.c)

# Create library target
add_library(malloc_toy SHARED ${SOURCES})

# Add include directories
target_include_directories(malloc_toy PUBLIC .)

# Add performance test target
add_executable(raw_performance_test tests/raw_performance.c)
add_executable(hook_performance_test tests/hook_performance.c)

add_executable(new_hook_performance_test tests/new_hook_performance.c)
target_include_directories(new_hook_performance_test PUBLIC .)
target_link_libraries(new_hook_performance_test malloc_toy)
set_target_properties(new_hook_performance_test PROPERTIES
    INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

install(TARGETS malloc_toy DESTINATION lib)

install(TARGETS raw_performance_test hook_performance_test
                new_hook_performance_test DESTINATION bin)
