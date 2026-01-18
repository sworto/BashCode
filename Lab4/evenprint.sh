#!/bin/bash
N=$1
while((i<=N)) do
	if((i%2==0)); then echo -n $i" "
	fi
	((i++))
done