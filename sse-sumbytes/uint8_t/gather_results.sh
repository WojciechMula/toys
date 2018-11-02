#!/bin/bash

function usage
{
    echo "$0 [-a sse|avx2] [-n name] [-k]"
}

BASENAME=results
ARCHITECTURE=sse
TARGET=benchmark
KEEP=0

while getopts ":a:n:hk" o
do
    case "${o}" in
        a)
            ARCHITECTURE=${OPTARG}
            if [[ ${ARCHITECTURE} == "sse" ]]
            then
                TARGET=benchmark
            elif [[ ${ARCHITECTURE} == "avx2" ]]
            then
                TARGET=benchmark_avx2
            else
                usage
                exit 1
            fi
            ;;
        n)
            BASENAME=${OPTARG}
            ;;
        k)
            KEEP=1
            ;;
        h)
            usage
            exit 0
            ;;
    esac
done

RESULTS_PATH=${BASENAME}.txt
META_PATH=${BASENAME}.meta
TABLE_PATH=${BASENAME}.table
ARCHIVE_PATH=${BASENAME}.tgz

function build_benchmark
{
    make ${TARGET}
}

function run_benchmark
{
    LOOPS=3
    echo "Running benchmark..."
    rm -f ${RESULTS_PATH}
    for i in `seq ${LOOPS}`
    do
        ./${TARGET} >> ${RESULTS_PATH}
    done
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
}


function create_table
{
    python scripts/format.py ${RESULTS_PATH} > ${TABLE_PATH}
}


function create_archive
{
    if [[ ${KEEP} == 1 ]]
    then
        tar -czf ${ARCHIVE_PATH} ${RESULTS_PATH} ${META_PATH} ${TABLE_PATH}
        echo "Files '${ARCHIVE_PATH}', '${RESULTS_PATH}', '${META_PATH}' and '${TABLE_PATH}' were created"
    else
        tar --remove-files -czf ${ARCHIVE_PATH} ${RESULTS_PATH} ${META_PATH} ${TABLE_PATH}
        echo "File '${ARCHIVE_PATH}' was created"
    fi
}

build_benchmark
run_benchmark
create_table
get_metadata
create_archive
