#!/bin/bash
file="precalc.c"

echo "byte quotient[2560] = {" > $file
for ((i=0 ; i<256 ; i++))
do
	if [ $i -ne 255 ]
	then
		echo $i, $i, $i, $i, $i, $i, $i, $i, $i, $i, >> $file
	else
		echo $i, $i, $i, $i, $i, $i, $i, $i, $i, $i  >> $file
	fi
done
echo "};" >> $file
echo ""   >> $file

echo "byte remainder[2560] = {" >> $file
for ((i=0 ; i<256 ; i++))
do
	if [ $i -ne 255 ]
	then
		echo "0, 1, 2, 3, 4, 5, 6, 7, 8, 9," >> $file
	else
		echo "0, 1, 2, 3, 4, 5, 6, 7, 8, 9"  >> $file
	fi
done
echo "};" >> $file

