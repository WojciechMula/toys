
program=./blur
log=blur.log
count=10000
time="/usr/bin/time -f %E -a -o $log"

rm -f $log
for procedure in x86 mmx mmx2 sse2
do
    echo "procedure $procedure..."

    echo -n "$procedure " >> $log
    $time $program test $procedure $count > /dev/null
done

cat $log
