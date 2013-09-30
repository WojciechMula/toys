#!/bin/sh

DICTIONARY=dictionary.txt
INPUT=input-words.txt
COUNT=100

for f in bin/*
do
	echo `basename $f`;
	$f $DICTIONARY $INPUT $COUNT | grep time
done
