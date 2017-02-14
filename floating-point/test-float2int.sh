#!/bin/sh
TIME="/usr/bin/time --format=%E"
ITERS=10000

for procedure in `seq 0 2`
do
    $TIME ./float2int $procedure $ITERS
done
