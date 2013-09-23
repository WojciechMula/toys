#!/bin/sh

DICTIONARY=dictionary.txt
INPUT=input-words.txt
INPUT_COUNT=`wc -l $INPUT | cut -d' ' -f1`
COUNT=10

for f in bin/*
do
	echo `basename $f`;
	$f $DICTIONARY $INPUT $INPUT_COUNT $COUNT | grep time
done
