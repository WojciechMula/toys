#!/bin/sh

DICTIONARY=dictionary.txt
INPUT=input-words.txt
COUNT=10

for f in bin/*
do
	echo `basename $f`;
	$f $DICTIONARY $INPUT $COUNT | grep time
done
