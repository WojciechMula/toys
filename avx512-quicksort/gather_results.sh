#!/bin/bash

if [[ $1 == "avx2" ]]
then
    SPEED=./speed_avx2
    if [[ ! -x $SPEED ]]
    then
        echo "AVX2 test program not found. Run make speed_avx2 to build it."
        exit 1
    fi
else
    SPEED=./speed
    if [[ ! -x $SPEED ]]
    then
        echo "AVX512 test program not found. Run make speed to build it."
        exit 1
    fi
fi


$SPEED    10000 3 asc | tee -a results.txt
$SPEED   100000 3 asc | tee -a results.txt
$SPEED  1000000 3 asc | tee -a results.txt
$SPEED  2000000 3 asc | tee -a results.txt
$SPEED  5000000 3 asc | tee -a results.txt
$SPEED 10000000 3 asc | tee -a results.txt
$SPEED 20000000 3 asc | tee -a results.txt

$SPEED    10000 3 dsc | tee -a results.txt
$SPEED   100000 3 dsc | tee -a results.txt
$SPEED  1000000 3 dsc | tee -a results.txt
$SPEED  2000000 3 dsc | tee -a results.txt
$SPEED  5000000 3 dsc | tee -a results.txt
$SPEED 10000000 3 dsc | tee -a results.txt
$SPEED 20000000 3 dsc | tee -a results.txt

$SPEED    10000 3 rnd | tee -a results.txt
$SPEED   100000 3 rnd | tee -a results.txt
$SPEED  1000000 3 rnd | tee -a results.txt
$SPEED  2000000 3 rnd | tee -a results.txt
$SPEED  5000000 3 rnd | tee -a results.txt
$SPEED 10000000 3 rnd | tee -a results.txt
$SPEED 20000000 3 rnd | tee -a results.txt

echo "results.txt created"
