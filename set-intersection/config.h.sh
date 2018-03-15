#!/bin/sh

CONFIG=config.h
CPUCHECK="python ../scripts/cpuflags.py"

echo '#pragma once' > $CONFIG
$CPUCHECK avx2 > /dev/null && echo "#define HAVE_AVX2 1" >> $CONFIG
$CPUCHECK sse  > /dev/null && echo "#define HAVE_SSE 1" >> $CONFIG

