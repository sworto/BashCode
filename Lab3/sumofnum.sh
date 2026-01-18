#!/bin/bash
N=$1
for (( i=1;i<=N;i++ )); do
	COUNT=$(( COUNT+ i ))
done
echo "SUM" $COUNT