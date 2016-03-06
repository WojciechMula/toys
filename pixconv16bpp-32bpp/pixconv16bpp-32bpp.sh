#!/bin/sh

opts="lookup8 lookup82 lookup16 naive MMX SSE2 SSE22"
iters=1000
app="./a.out"
for opt in $opts
do
	rm $opt.log 2> /dev/null
	for i in `seq 10`
	do
		echo -n "$i "
		$app $opt $iters >> $opt.log
	done
done
