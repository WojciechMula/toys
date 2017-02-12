#!/bin/sh
./demo sse32 0 99999999 | awk \
    '$1 != $3 {printf("ERROR >%s< >%s<\n", $1, $3); exit 1}'

