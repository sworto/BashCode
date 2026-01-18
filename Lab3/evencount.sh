#!/bin/bash
N=$1
COUNT=0
for (( i=1;i<N;i++ )); do
	if((i%2==0)); then ((COUNT++))
	fi
done
echo "Total even numbers: " $COUNT