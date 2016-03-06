#!/bin/sh

opts="lookup8 lookup82 lookup16 naive MMX SSE2 SSE22"
iters=100
program=$1
programlog=$1.log

rm $programlog 2> /dev/null

for opt in $opts
do
    log=$program-$opt.log
	rm $log 2> /dev/null
    echo -n "$opt ["
	for i in `seq $iters`
	do
		echo -n "."
		./$program $opt $iters >> $log
	done

    echo "]"

    echo -n "$opt " >> $programlog
    cat $log | awk '$1 == "time" {print $3}' | sort -n | head -n 1 >> $programlog
done
