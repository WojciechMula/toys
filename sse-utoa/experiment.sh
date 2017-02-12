#!/bin/sh

TIME="/usr/bin/time --format="%E" --quiet"

algorithm_1() {
    echo "Algorithm #1, range=[$1, $2], iterations=$2"
    echo -n "\tC    : "
    $TIME ./demo c32   $1 $2 $3
    echo -n "\tSSE32: "
    $TIME ./demo sse32 $1 $2 $3
    echo
}


algorithm_2() {
    echo "Algorithm #2, range=[$1, $2], iterations=$2"
    echo -n "\tC    : "
    $TIME ./demo c32     $1 $2 $3
    echo -n "\tSSE32: "
    $TIME ./demo sse32_2 $1 $2 $3
    echo
}

compare() {
    prog=$1
    $prog        0       99    100000
    $prog        0     9999      1000
    $prog        0 99999999         1
    $prog 10000000 99999999         1
}


compare algorithm_1
compare algorithm_2
