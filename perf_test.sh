#!/bin/bash

# Run the performance tests
for test_file in install/bin/*test; do
  echo "Running performance test: $test_file"
  time $test_file
done