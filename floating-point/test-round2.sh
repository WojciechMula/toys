#!/bin/sh
TIME="/usr/bin/time --format=%E"
ITERS=10000

for procedure in `seq 0 3`
do
    $TIME ./round2 $procedure $ITERS
done
