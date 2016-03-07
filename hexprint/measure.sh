#!/usr/bin/bash

program=$1
log=$program.log
time="/usr/bin/time -f %E -a -o $log"

rm -f $log
for method in std std2 std3 ssse3
do
    echo "method $method ..."
    echo -n "method $method " >> $log
    $time ./$program $method > /dev/null
done

cat $log
