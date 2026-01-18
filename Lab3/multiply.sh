#!/bin/bash
NUM=$1
for (( i=1;i<=10;i++ )) do
	echo $NUM"x"$i"="$((NUM*i))
done