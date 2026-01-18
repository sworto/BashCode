#!/bin/bash
N=$1
i=1
FACTORIAL=1;
if((N==0)); then echo "Factorial: 1"
else
	while((i<=N)) do
		((FACTORIAL=FACTORIAL*i))
		((i++))
	done
	echo "Factorial: "$FACTORIAL
fi