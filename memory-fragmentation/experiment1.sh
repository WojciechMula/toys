#!/bin/bash

_1MB=1048576
_10MB=10485760
_100MB=104857600

TOTAL_SIZE="$_1MB $_10MB $_100MB"
ALLOC_SIZE="$(seq 1 32) 48 64 128 256 512 1024 2048"

for total_size in ${TOTAL_SIZE}
do
    for alloc_size in ${ALLOC_SIZE}
    do
        ./test ${total_size} ${alloc_size}
    done
done
