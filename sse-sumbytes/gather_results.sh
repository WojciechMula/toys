#!/bin/bash

BASENAME=results
RESULTS_PATH=${BASENAME}.txt
META_PATH=${BASENAME}.meta
TABLE_PATH=${BASENAME}.table

function run_benchmark
{
    LOOPS=3
    echo "Running benchmark..."
    rm -f ${RESULTS_PATH}
    for i in `seq ${LOOPS}`
    do
        ./benchmark >> ${RESULTS_PATH}
    done

    echo "File '${RESULTS_PATH}' was created"
}


function get_metadata
{
    CPUINFO=$(awk -F: '/^model name/ {
        gsub(/^[ ]+/, "", $2);  # remove leading spaces
        gsub(/[ ]+$/, "", $2);  # remove trailing spaces
        gsub(/[ ]+/, " ", $2);  # normalize spaces
        print $2;
        exit                    # print just 1st CPU
    }' < /proc/cpuinfo)

    GCCVERSION=$(gcc --version | head -n1)

    rm -f ${META_PATH}
    echo "CPU: ${CPUINFO}" >> ${META_PATH}
    echo "GCC: ${GCCVERSION}" >> ${META_PATH}

    echo "File '${META_PATH}' was created"
}


function create_table
{
    python scripts/format.py ${RESULTS_PATH} > ${TABLE_PATH}
    echo "File '${TABLE_PATH}' was created"
}

run_benchmark
create_table
get_metadata
