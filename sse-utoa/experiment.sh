#!/bin/sh

prog=./benchmark
$prog        0       99    100000
$prog        0     9999      1000
$prog        0 99999999         1
$prog 10000000 99999999         1
